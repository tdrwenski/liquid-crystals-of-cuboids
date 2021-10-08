#ifndef __Integrator__
#define __Integrator__

#include <cuba.h>
#include <iostream>

class Integrator {
private:
    static const int s_components = 1;

public:
    Integrator(int dimensions, integrand_t pIntegrand) : m_dimensions(dimensions), m_pIntegrand(pIntegrand) {}

public:
    void integrate(void* pParameters) {
        Cuhre(m_dimensions, s_components, m_pIntegrand, pParameters, m_nvec, m_relativeTolerance,
              m_absoluteTolerance, m_flags, m_minEvaluations, m_maxEvaluations, m_key, m_statefile,
              m_spinningCores, &m_numberOfRegions, &m_numberOfEvaluations, &m_fail, m_integral, m_error,
              m_chiSquaredProbabiltyForError);
    }

    double getIntegral() const { return m_integral[0]; }
    double getError() const { return m_error[0]; }
    double getErrorProbability() const { return m_chiSquaredProbabiltyForError[0]; }

    void printResults() const {

        if (!m_fail) {
            std::cout << "Integration succeeded!" << std::endl;
        } else {
            std::cout << "Integration failed with code: " << m_fail << std::endl;
        }

        std::cout << "Result: " << m_integral[0] << ", error: " << m_error[0]
                  << ", probability: " << m_chiSquaredProbabiltyForError[0]
                  << ", regions: " << m_numberOfRegions << ", evaluations: " << m_numberOfEvaluations
                  << std::endl;
    }

private:
    // inputs
    const int m_dimensions;
    const integrand_t m_pIntegrand;
    int m_nvec = 1; // use 1 unless integrand needs SIMD vectorization
    double m_relativeTolerance = 10e-6;
    double m_absoluteTolerance = 10e-6;
    int m_minEvaluations = 1;
    int m_maxEvaluations = 10e8;
    int m_flags = 0;
    int m_key = 0;
    const char* m_statefile = nullptr; // don't store internal states
    void* m_spinningCores = nullptr;   // Let cuba handle starting/ terminating child processes

    // outputs
    int m_numberOfRegions;
    int m_numberOfEvaluations;
    int m_fail;
    double m_integral[s_components];
    double m_error[s_components];
    double m_chiSquaredProbabiltyForError[s_components];
};

#endif
