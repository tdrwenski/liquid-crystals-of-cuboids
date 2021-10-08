#ifndef __Spherocylinder__
#define __Spherocylinder__

#include <math.h>
#include <vector>

class Spherocylinder {

public:
    Spherocylinder(double lengthToDiameter) : m_length(lengthToDiameter) {}

public:
    double getVolume() const { return M_PI * m_length / 4.0 + M_PI / 6.0; }

    double getLength() const { return m_length; }

    double excludedVolume(double /*alpha*/, double beta, double /*gamma*/) const {
        return 2 * m_length * m_length * fabs(sin(beta)) + 2 * M_PI * m_length + 4.0 / 3.0 * M_PI;
    }

private:
    const double m_length;
};

#endif
