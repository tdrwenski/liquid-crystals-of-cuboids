#include "SecondVirialWignerEquations.h"
#include "ExcludedVolumeCoefficients.h"
#include "Integrator.h"
#include "WignerMatrices.h"
#include "gsl/gsl_vector_double.h"
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace {

struct NormIntegrationParams : SecondVirialParams {
    const gsl_vector* pRealPsiCoefficients;
};

struct IntegrationParams : NormIntegrationParams {
    const Indices* pCurrentIndices;
};

double calculatePsi(const NormIntegrationParams* pIntegrationParams, const double& alpha, const double& beta,
                    const double& gamma) {
    double sum = 0;

    for (size_t i = 0; i < pIntegrationParams->pIndices->size(); ++i) {
        const int l = pIntegrationParams->pIndices->at(i).l;
        const int m = pIntegrationParams->pIndices->at(i).m;
        const int n = pIntegrationParams->pIndices->at(i).n;

        const double psiReal = gsl_vector_get(pIntegrationParams->pRealPsiCoefficients, i);

        const int coefficient = (m == 0 && n == 0) ? 1 : 2;

        sum += coefficient * psiReal * wignerDReal(l, m, n, alpha, beta, gamma);
    }

    return exp(sum);
}

int normIntegrand(const int* /*nDim*/, const double omega[], const int* /*nComp*/, double f[],
                  void* pParams) {
    // change integration region to unit cube
    const double alpha = 2 * M_PI * omega[0];
    const double beta = M_PI * omega[1];
    const double gamma = 2 * M_PI * omega[2];
    const double jacobian = 4 * pow(M_PI, 3) * sin(beta);

    const auto pIntegrationParams = static_cast<NormIntegrationParams*>(pParams);

    const double psi = calculatePsi(pIntegrationParams, alpha, beta, gamma);
    f[0] = jacobian * psi;

    return 0;
}

int integrand(const int* /*nDim*/, const double omega[], const int* /*nComp*/, double f[], void* pParams) {
    const double alpha = 2 * M_PI * omega[0];
    const double beta = M_PI * omega[1];
    const double gamma = 2 * M_PI * omega[2];
    const double jacobian = 4 * pow(M_PI, 3) * sin(beta);

    const auto pIntegrationParams = static_cast<IntegrationParams*>(pParams);

    double psi = calculatePsi(pIntegrationParams, alpha, beta, gamma);

    const int l = pIntegrationParams->pCurrentIndices->l;
    const int m = pIntegrationParams->pCurrentIndices->m;
    const int n = pIntegrationParams->pCurrentIndices->n;

    f[0] = 0.;

    for (int p = -l; p <= l; ++p) {
        f[0] += pIntegrationParams->pExcludedVolumeCoefficients->getReal(l, p, n) * psi *
                    wignerDReal(l, m, p, alpha, beta, gamma) +
                pIntegrationParams->pExcludedVolumeCoefficients->getImaginary(l, p, n) * psi *
                    wignerDImag(l, m, p, alpha, beta, gamma);
    }

    f[0] *= jacobian;

    return 0;
}

// Euler Lagrange equations, to be minimized
// must have function_t signature
int equations(const gsl_vector* pPsi, void* pParams, gsl_vector* pF) {

    auto pSecondVirialParams = static_cast<SecondVirialParams*>(pParams);
    NormIntegrationParams normParams = {{*pSecondVirialParams}, pPsi};

    Integrator normIntegrator(3, normIntegrand);
    normIntegrator.integrate(&normParams);

    IntegrationParams integrationParams = {{normParams}, nullptr};
    Integrator integrator(3, integrand);

    size_t iEquation = 0;

    const double rho = pSecondVirialParams->packingFraction / pSecondVirialParams->particleVolume;

    for (const auto& indices : *integrationParams.pIndices) {
        integrationParams.pCurrentIndices = &indices;

        integrator.integrate(&integrationParams);

        const double psi = gsl_vector_get(pPsi, iEquation);
        const double functionValue = rho * integrator.getIntegral() / normIntegrator.getIntegral() + psi;

        gsl_vector_set(pF, iEquation, functionValue);

        ++iEquation;
    }

    return GSL_SUCCESS;
}

int sigma(const int* nDim, const double omega[], const int* nComp, double f[], void* pParams) {
    const double alpha = 2 * M_PI * omega[0];
    const double beta = M_PI * omega[1];
    const double gamma = 2 * M_PI * omega[2];
    const double jacobian = 4 * pow(M_PI, 3) * sin(beta);

    const auto pIntegrationParams = static_cast<IntegrationParams*>(pParams);

    double psi = calculatePsi(pIntegrationParams, alpha, beta, gamma);

    f[0] = jacobian * psi * log(psi);

    return 0;
}

int orderParameter(const int* /*nDim*/, const double omega[], const int* /*nComp*/, double f[],
                   void* pParams) {
    const double alpha = 2 * M_PI * omega[0];
    const double beta = M_PI * omega[1];
    const double gamma = 2 * M_PI * omega[2];
    const double jacobian = 4 * pow(M_PI, 3) * sin(beta);

    const auto pIntegrationParams = static_cast<IntegrationParams*>(pParams);

    double psi = calculatePsi(pIntegrationParams, alpha, beta, gamma);

    const int l = pIntegrationParams->pCurrentIndices->l;
    const int m = pIntegrationParams->pCurrentIndices->m;
    const int n = pIntegrationParams->pCurrentIndices->n;

    f[0] = jacobian * psi * wignerDReal(l, m, n, alpha, beta, gamma);

    return 0;
}

double returnOrderParameter(const std::vector<std::tuple<Indices, double>>& orderParameters, int l, int m,
                            int n) {

    if (l == 0 && m == 0 && n == 0) return 1.0;

    auto iterator = std::find_if(
        orderParameters.begin(), orderParameters.end(), [&](const std::tuple<Indices, double>& elem) {
            return std::get<0>(elem).l == l && std::get<0>(elem).m == m && std::get<0>(elem).n == n;
        });

    if (iterator != orderParameters.end()) return std::get<1>(*iterator);

    iterator = std::find_if(
        orderParameters.begin(), orderParameters.end(), [&](const std::tuple<Indices, double>& elem) {
            return std::get<0>(elem).l == l && std::get<0>(elem).m == -m && std::get<0>(elem).n == -n;
        });

    return iterator == orderParameters.end() ? 0.0 : pow(-1, m - n) * std::get<1>(*iterator);
}

} // namespace

void SecondVirialWignerEquations::calculateThermodynamics(const SecondVirialParams& params,
                                                          const gsl_vector* pPsi) {

    NormIntegrationParams normParams = {{params}, pPsi};

    Integrator normIntegrator(3, normIntegrand);
    normIntegrator.integrate(&normParams);
    const double norm = normIntegrator.getIntegral();

    Integrator sigmaIntegrator(3, sigma);
    sigmaIntegrator.integrate(&normParams);
    const double sigma = sigmaIntegrator.getIntegral();

    Integrator orderParameterIntegrator(3, orderParameter);
    IntegrationParams integrationParams = {{normParams}, nullptr};

    std::vector<std::tuple<Indices, double>> orderParameters;

    for (const auto& indices : *integrationParams.pIndices) {
        integrationParams.pCurrentIndices = &indices;
        orderParameterIntegrator.integrate(&integrationParams);
        const double orderParameter = orderParameterIntegrator.getIntegral() / norm;
        orderParameters.push_back(std::make_pair(indices, orderParameter));
    }

    double secondVirialTerm = 0;

    for (int l = 0; l <= m_config.getLMax(); ++l) {
        for (int m = -l; m <= l; ++m) {
            for (int n = -l; n <= l; ++n) {

                double secondVirialRe = 0.0;

                for (int p = -l; p <= l; ++p) {
                    secondVirialRe += returnOrderParameter(orderParameters, l, p, m) *
                                      returnOrderParameter(orderParameters, l, p, n);
                }

                secondVirialTerm +=
                    integrationParams.pExcludedVolumeCoefficients->getReal(l, m, n) * secondVirialRe;
            }
        }
    }

    const double eta = params.packingFraction;
    const double rho = params.packingFraction / params.particleVolume;

    double freeEnergy = -1. + log(eta) + sigma / norm - log(norm) + rho / 2.0 * secondVirialTerm;
    double fIso = -1 + log(eta) + rho / 2.0 * params.pExcludedVolumeCoefficients->getReal(0, 0, 0) -
                  log(8 * M_PI * M_PI);
    double pressure = eta + eta * rho / 2.0 * secondVirialTerm;
    double chemPot = pressure / eta + freeEnergy;

    const double uniaxialS = returnOrderParameter(orderParameters, 2, 0, 0);
    const double uniaxialU = sqrt(2) * returnOrderParameter(orderParameters, 2, 0, 2);
    const double biaxialP = sqrt(2) * returnOrderParameter(orderParameters, 2, 2, 0);
    const double biaxialF =
        returnOrderParameter(orderParameters, 2, 2, 2) + returnOrderParameter(orderParameters, 2, -2, 2);

    m_resultsFile << eta << m_sep;
    m_resultsFile << freeEnergy << m_sep << fIso << m_sep << pressure << m_sep << chemPot << m_sep;
    m_resultsFile << uniaxialS << m_sep << uniaxialU << m_sep << biaxialP << m_sep << biaxialF;

    m_resultsFile << std::endl;
}

void SecondVirialWignerEquations::writeThermodynamicsToFile(int startingGuessIndex,
                                                            const SecondVirialParams& params,
                                                            const gsl_vector* pPsi) {
    if (m_resultsFile.is_open()) {
        m_resultsFile << startingGuessIndex << m_sep;
        calculateThermodynamics(params, pPsi);
    }
}

function_t SecondVirialWignerEquations::getEquations() { return &equations; }

namespace {

void createResultsDirectory() {
    if (!std::filesystem::exists("results")) {
        if (!std::filesystem::create_directory("results")) {
            throw std::runtime_error("Directory `results` could not be created.");
        }
    }
}

std::string createResultsFile(const ParticleModel_t& particle) {

    createResultsDirectory();
    std::ostringstream fileName;

    if (std::holds_alternative<Cuboid>(particle)) {
        const Cuboid& cuboid = std::get<Cuboid>(particle);
        fileName << "results/results_cuboid_" << cuboid.getLength() << "_" << cuboid.getWidth() << ".txt";
    } else {
        const Spherocylinder& spherocylinder = std::get<Spherocylinder>(particle);
        fileName << "results/results_spherocylinder_" << spherocylinder.getLength() << ".txt";
    }

    return fileName.str();
}

} // namespace

SecondVirialWignerEquations::SecondVirialWignerEquations(const ParticleModel_t& particle,
                                                         const Config& config) :
    m_resultsFile(createResultsFile(particle)), m_config(config) {

    m_resultsFile << std::fixed << std::setprecision(8);

    if (m_resultsFile.is_open()) {

        m_resultsFile << "guess#,eta,freeEnergy,freeEnergyIso,pressure,chemicalPotential,S,U,P,F"
                      << std::endl;
    }
}

SecondVirialWignerEquations::~SecondVirialWignerEquations() {
    if (m_resultsFile.is_open()) {
        m_resultsFile.close();
    }
}