#include "RootFinder.h"
#include <gsl/gsl_errno.h>
#include <iostream>

void RootFinder::printState() const {

    std::cout << "  psi = ";
    for (size_t i = 0; i < m_dimension; ++i) std::cout << gsl_vector_get(m_pSolver->x, i) << ", ";
    std::cout << std::endl;

    std::cout << "  f(psi) = ";
    for (size_t i = 0; i < m_dimension; ++i) std::cout << gsl_vector_get(m_pSolver->f, i) << ", ";
    std::cout << std::endl;
}

void RootFinder::setStartPoint(const gsl_vector* startPoint) {
    gsl_multiroot_fsolver_set(m_pSolver, &m_function, startPoint);
}

const gsl_vector* RootFinder::getSolution() const { return m_pSolver->x; }

void RootFinder::solve() {

    int solverStatus = GSL_CONTINUE;
    int iter = 0;
    int maxIter = 100000;

    printState();

    while (solverStatus == GSL_CONTINUE && iter < maxIter) {
        ++iter;
        const int iterateStatus = gsl_multiroot_fsolver_iterate(m_pSolver);

        if (iterateStatus != GSL_SUCCESS) break; // solver is stuck

        solverStatus = gsl_multiroot_test_residual(m_pSolver->f, m_tolerance);

        if (solverStatus == GSL_SUCCESS) std::cout << "Converged in " << iter << " iterations." << std::endl;
    }

    printState();

    std::cout << "status = " << gsl_strerror(solverStatus) << std::endl;
}