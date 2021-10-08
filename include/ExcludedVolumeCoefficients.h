#ifndef __ExcludedVolumeCoefficients__
#define __ExcludedVolumeCoefficients__

#include "Config.h"
#include <FileReader.h>

#include <vector>

class ExcludedVolumeCoefficients {
public:
    ExcludedVolumeCoefficients(size_t maxOrderInL, const ParticleModel_t& particle);

public:
    double getReal(int L, int m, int n) const { return m_real.at(getVectorIndex(L, m, n)); }

    double getImaginary(int L, int m, int n) const { return m_imaginary.at(getVectorIndex(L, m, n)); }

protected:
    int getVectorIndex(int L, int m, int n) const {
        int size = 2 * m_maxOrderInL + 1;
        return n + L + size * (m + L) + L * size * size;
    }

    void setReal(int L, int m, int n, double value) {
        if (L <= m_maxOrderInL) {
            m_real.at(getVectorIndex(L, m, n)) = value;
        }
    }

    void setImaginary(int L, int m, int n, double value) {
        if (L <= m_maxOrderInL) {
            m_imaginary.at(getVectorIndex(L, m, n)) = value;
        }
    }

    // For testing
    ExcludedVolumeCoefficients(size_t maxOrderInL) :
        m_maxOrderInL(maxOrderInL),
        m_totalSize(5 * maxOrderInL + 8 * maxOrderInL * maxOrderInL +
                    4 * maxOrderInL * maxOrderInL * maxOrderInL + 1),
        m_real(m_totalSize, 0.0),
        m_imaginary(m_totalSize, 0.0) {}

private:
    void readCoefficientsFromFile(FileReader& fileReader);
    void computeCoefficients(size_t maxOrderInL, const ParticleModel_t& particle);
    void writeToFile(std::string fileName, size_t maxOrderInL);

private:
    size_t m_maxOrderInL;
    size_t m_totalSize;
    std::vector<double> m_real;
    std::vector<double> m_imaginary;
};

#endif
