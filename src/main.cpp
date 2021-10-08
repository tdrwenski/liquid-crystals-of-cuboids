#include "Config.h"
#include "ExcludedVolumeCoefficients.h"
#include "Integrator.h"
#include "RootFinder.h"
#include "SecondVirialWignerEquations.h"
#include "gsl/gsl_vector_double.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <variant>

namespace {

void printIndexInfo(const std::vector<Indices>& indices) {
    std::cout << "solving for indices l,m,n= " << std::endl;
    for (const auto& index : indices) {
        std::cout << index.l << ", " << index.m << ", " << index.n << std::endl;
    }
}
void printParticleInfo(const ParticleModel_t& particle) {

    std::cout << "*****************" << std::endl;

    if (std::holds_alternative<Cuboid>(particle)) {
        const Cuboid& cuboid = std::get<Cuboid>(particle);
        std::cout << "Cuboid with dimensions: " << cuboid.getLength() << ", " << cuboid.getWidth()
                  << " and volume = " << cuboid.getVolume() << std::endl;

    } else {
        const Spherocylinder& spherocylinder = std::get<Spherocylinder>(particle);
        std::cout << "Spherocylinder with dimension: " << spherocylinder.getLength() << std::endl;
    }
}

void copyStartPoints(std::vector<gsl_vector*>& destination, const std::vector<gsl_vector*>& source) {
    for (const auto& pStartPoint : source) {
        gsl_vector* pNewStartPoint = gsl_vector_alloc(pStartPoint->size);
        gsl_vector_memcpy(pNewStartPoint, pStartPoint);
        destination.push_back(pNewStartPoint);
    }
}

} // namespace

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "Expected usage `./run config_file.txt`" << std::endl;
        return 0;
    }

    Config config(argv[1], ',');
    printIndexInfo(config.getIndices());

    for (const auto& particle : config.getParticleModels()) {

        printParticleInfo(particle);

        ExcludedVolumeCoefficients excludedVolumeCoefficients(config.getLMax(), particle);

        const double volume = std::visit([](const auto& p) { return p.getVolume(); }, particle);
        SecondVirialParams params = {&config.getIndices(), &excludedVolumeCoefficients, volume, 0.};

        SecondVirialWignerEquations secondVirialWignerEquations(particle, config);

        const PackingFractions& etas = config.getPackingFractions();

        std::vector<gsl_vector*> startingPoints;
        copyStartPoints(startingPoints, config.getStartingPoints());

        for (double eta = etas.max; eta >= etas.min; eta -= etas.increment) {
            std::cout << "--------------" << std::endl << "Eta: " << eta << std::endl;

            params.packingFraction = eta;

            for (int i = 0; i < config.getStartingPoints().size(); ++i) {

                RootFinder rootFinder(&params, SecondVirialWignerEquations::getEquations(),
                                      gsl_multiroot_fsolver_hybrids, config.getDimension(), 0.0001);

                rootFinder.setStartPoint(startingPoints[i]);

                rootFinder.solve();

                secondVirialWignerEquations.writeThermodynamicsToFile(i, params, rootFinder.getSolution());

                // Use solution as the starting point for the next packing fraction
                gsl_vector_memcpy(startingPoints[i], rootFinder.getSolution());
            }
        }
    }

    return 0;
}
