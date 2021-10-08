#ifndef __SecondVirialWignerEquations__
#define __SecondVirialWignerEquations__

#include "Config.h"
#include "RootFinder.h"
#include <fstream>
#include <gsl/gsl_multiroots.h>
#include <iostream>
#include <string>
#include <vector>

class ExcludedVolumeCoefficients;

struct SecondVirialParams {
    const std::vector<Indices>* pIndices;
    const ExcludedVolumeCoefficients* pExcludedVolumeCoefficients;

    double particleVolume;
    double packingFraction;
};

class SecondVirialWignerEquations {
public:
    SecondVirialWignerEquations(const ParticleModel_t& particle, const Config& config);
    ~SecondVirialWignerEquations();

public:
    static function_t getEquations();
    void writeThermodynamicsToFile(int startingGuessIndex, const SecondVirialParams& params,
                                   const gsl_vector* pPsi);

private:
    void calculateThermodynamics(const SecondVirialParams& params, const gsl_vector* pPsi);

private:
    std::ofstream m_resultsFile;
    char m_sep = ',';
    const Config& m_config;
};

#endif
