#include "Integrator.h"
#include <gtest/gtest.h>
#include <math.h>

namespace {

int integrand(const int* /*nDim*/, const double x[], const int* /*nComp*/, double f[], void* /*params*/) {
    // change integration region to unit cube
    // x[0] = alpha/2pi
    // x[1] = beta/pi
    // x[2] = gamma/2pi

    double beta = M_PI * x[1];

    const double jacobian = 4 * pow(M_PI, 3) * sin(beta);

    f[0] = jacobian / (8 * M_PI * M_PI);

    return 0;
}

} // namespace

TEST(IntegratorTest, shouldIntegrateInSphericalCoordinates) {

    Integrator integrator(3, integrand);
    integrator.integrate(nullptr);

    ASSERT_NEAR(integrator.getIntegral(), 1.0, 1e-6);
    ASSERT_NEAR(integrator.getError(), 0.0, 1e-6);
    ASSERT_NEAR(integrator.getErrorProbability(), 0.0, 1e-1);
}