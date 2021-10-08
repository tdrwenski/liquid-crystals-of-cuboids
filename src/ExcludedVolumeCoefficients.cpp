#include "ExcludedVolumeCoefficients.h"
#include "FileReader.h"
#include "Integrator.h"
#include "WignerMatrices.h"
#include <exception>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace {

std::string getFileName(const ParticleModel_t& particle) {

    std::ostringstream fileName;
    fileName.precision(1);
    fileName.setf(std::ios::fixed, std::ios::floatfield);

    if (std::holds_alternative<Cuboid>(particle)) {
        const Cuboid& cuboid = std::get<Cuboid>(particle);
        fileName << "excludedVolumeCoefficients/evol_cuboids_l" << cuboid.getLength() << "_m"
                 << cuboid.getWidth() << ".txt";
    } else {
        const Spherocylinder& spherocylinder = std::get<Spherocylinder>(particle);
        fileName << "excludedVolumeCoefficients/evol_spherocylinders_l" << spherocylinder.getLength()
                 << ".txt";
    }

    return fileName.str();
}

} // namespace

ExcludedVolumeCoefficients::ExcludedVolumeCoefficients(size_t maxOrderInL, const ParticleModel_t& particle) :
    m_maxOrderInL(maxOrderInL),
    m_totalSize(5 * maxOrderInL + 8 * maxOrderInL * maxOrderInL +
                4 * maxOrderInL * maxOrderInL * maxOrderInL + 1),
    m_real(m_totalSize, 0.0),
    m_imaginary(m_totalSize, 0.0) {

    const std::string fileName = getFileName(particle);

    try {
        FileReader fileReader(fileName, ' ');
        readCoefficientsFromFile(fileReader);
        std::cout << "Read excluded volume coefficients from file: " << fileName << std::endl;
    } catch (const std::exception&) {
        std::cout << "Computing excluded volume coefficients up to l=" << maxOrderInL << std::endl;
        computeCoefficients(maxOrderInL, particle);
        std::cout << "Writing excluded volume coefficients to file: " << fileName << std::endl;
        writeToFile(fileName, maxOrderInL);
    }
}

void ExcludedVolumeCoefficients::readCoefficientsFromFile(FileReader& fileReader) {
    std::string line;
    int lineNumber = 0;

    while (fileReader.getLine(line)) {
        ++lineNumber;
        std::vector<double> items = fileReader.split(line);

        if (items.size() != 4) {
            throw std::runtime_error("Expected 4 columns in excluded volume data file, but found " +
                                     std::to_string(items.size()));
        }

        lineNumber % 2 ? setReal(items[0], items[1], items[2], items[3])
                       : setImaginary(items[0], items[1], items[2], items[3]);
    }
}

namespace {

struct ExcludedVolumeIntegrationParams {
    const Indices indices;
    const ParticleModel_t& particle;
};

int realExcludedVolumeIntegrand(const int* /*nDim*/, const double omega[], const int* /*nComp*/, double f[],
                                void* pParams) {
    const double alpha = 2 * M_PI * omega[0];
    const double beta = M_PI * omega[1];
    const double gamma = 2 * M_PI * omega[2];
    const double jacobian = 4 * pow(M_PI, 3) * sin(beta);

    const auto pIntegrationParams = static_cast<ExcludedVolumeIntegrationParams*>(pParams);
    const Indices& indices = pIntegrationParams->indices;
    const ParticleModel_t& particle = pIntegrationParams->particle;
    const double excludedVolume =
        std::visit([&](const auto& p) { return p.excludedVolume(alpha, beta, gamma); }, particle);

    f[0] = jacobian * (2 * indices.l + 1) / (8 * M_PI * M_PI) * excludedVolume *
           wignerDReal(indices.l, indices.m, indices.n, alpha, beta, gamma);

    return 0;
}

int imaginaryExcludedVolumeIntegrand(const int* /*nDim*/, const double omega[], const int* /*nComp*/,
                                     double f[], void* pParams) {
    const double alpha = 2 * M_PI * omega[0];
    const double beta = M_PI * omega[1];
    const double gamma = 2 * M_PI * omega[2];
    const double jacobian = 4 * pow(M_PI, 3) * sin(beta);

    const auto pIntegrationParams = static_cast<ExcludedVolumeIntegrationParams*>(pParams);
    const Indices& indices = pIntegrationParams->indices;
    const ParticleModel_t& particle = pIntegrationParams->particle;
    const double excludedVolume =
        std::visit([&](const auto& p) { return p.excludedVolume(alpha, beta, gamma); }, particle);

    f[0] = -jacobian * (2 * indices.l + 1) / (8 * M_PI * M_PI) * excludedVolume *
           wignerDImag(indices.l, indices.m, indices.n, alpha, beta, gamma);
    return 0;
}

} // namespace

void ExcludedVolumeCoefficients::computeCoefficients(size_t maxOrderInL, const ParticleModel_t& particle) {

    Integrator realIntegrator(3, realExcludedVolumeIntegrand);
    Integrator imaginaryIntegrator(3, imaginaryExcludedVolumeIntegrand);

    for (int l = 0; l <= maxOrderInL; ++l) {
        for (int m = -l; m <= l; ++m) {
            for (int n = -l; n <= l; ++n) {
                ExcludedVolumeIntegrationParams params{{l, m, n}, particle};

                realIntegrator.integrate(&params);
                setReal(l, m, n, realIntegrator.getIntegral());

                imaginaryIntegrator.integrate(&params);
                setImaginary(l, m, n, imaginaryIntegrator.getIntegral());
            }
        }
    }
}

void ExcludedVolumeCoefficients::writeToFile(std::string fileName, size_t maxOrderInL) {

    std::ofstream file(fileName);
    file << std::fixed << std::setprecision(8);
    const char delimiter = ' ';

    if (file.is_open()) {
        file << "# l m n Re/Im" << std::endl;
        for (int l = 0; l <= maxOrderInL; ++l) {
            for (int m = -l; m <= l; ++m) {
                for (int n = -l; n <= l; ++n) {
                    file << l << delimiter << m << delimiter << n << delimiter << getReal(l, m, n)
                         << std::endl;
                    file << l << delimiter << m << delimiter << n << delimiter << getImaginary(l, m, n)
                         << std::endl;
                }
            }
        }
    }
}
