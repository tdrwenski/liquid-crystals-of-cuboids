#ifndef __RootFinder__
#define __RootFinder__

#include <gsl/gsl_multiroots.h>

using function_t = int (*)(const gsl_vector*, void*, gsl_vector*);

class RootFinder {
public:
    RootFinder(void* pParameters, function_t function, const gsl_multiroot_fsolver_type* solverType,
               int dimension, double tolerance) :
        m_pParameters(pParameters), m_dimension(dimension), m_tolerance(tolerance) {
        m_function.f = function;
        m_function.params = m_pParameters;
        m_function.n = dimension;

        m_pSolver = gsl_multiroot_fsolver_alloc(solverType, dimension);
    }

public:
    void setStartPoint(const gsl_vector* startPoint);
    void solve();
    const gsl_vector* getSolution() const;

private:
    void printState() const;

private:
    void* m_pParameters;
    gsl_multiroot_function m_function;
    gsl_multiroot_fsolver* m_pSolver;
    int m_dimension;
    double m_tolerance;
};

#endif
