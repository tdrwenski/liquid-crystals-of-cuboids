#include "ExcludedVolumeCoefficients.h"
#include "Config.h"
#include <gtest/gtest.h>
#include <istream>

namespace {

class TestExcludedVolumeCoefficients : public ExcludedVolumeCoefficients {

public:
    TestExcludedVolumeCoefficients(size_t maxOrderInL) : ExcludedVolumeCoefficients(maxOrderInL) {}

public:
    double setAndGetReal(int L, int m, int n, double value) {
        setReal(L, m, n, value);
        return getReal(L, m, n);
    }
};

} // namespace

TEST(ExcludedVolumeCoefficients, shouldSetVectorElement) {

    TestExcludedVolumeCoefficients excludedVolumeCoefficients(2);

    EXPECT_EQ(excludedVolumeCoefficients.setAndGetReal(1, 1, -1, 0.5), 0.5);
    EXPECT_EQ(excludedVolumeCoefficients.setAndGetReal(2, 2, 2, -0.5), -0.5);
    EXPECT_EQ(excludedVolumeCoefficients.setAndGetReal(2, -2, -2, 0.5), 0.5);
}

TEST(ExcludedVolumeCoefficients, shouldThrowIfOutOfBounds) {

    TestExcludedVolumeCoefficients excludedVolumeCoefficients(2);

    try {
        excludedVolumeCoefficients.setAndGetReal(3, 1, -1, 0.5);
        FAIL() << "Expected exception";
    } catch (...) {
    }
}
