#ifndef __Cuboid__
#define __Cuboid__

#include <math.h>
#include <vector>

class Cuboid {

public:
    Cuboid(double lengthToThickness, double widthToThickness) :
        m_length(lengthToThickness), m_width(widthToThickness) {}

public:
    // Needs to match units used in excluded volume
    double getVolume() const { return m_length * m_width / pow((2 * m_width + 2) / M_PI, 3); }

    double getLength() const { return m_length; }
    double getWidth() const { return m_width; }

    double excludedVolume(double alpha, double beta, double gamma) const {

        const double a = 1.0;
        const double b = m_width;
        const double c = m_length;
        const double unitConverter = 1.0 / pow((2 * m_width + 2) / M_PI, 3);

        return unitConverter *
               (2 * a * b * c + 2 * a * b * c * fabs(cos(beta)) +
                a * b *
                    (b * (fabs(cos(alpha) * sin(beta)) + fabs(cos(gamma) * sin(beta))) +
                     a * (fabs(sin(beta) * sin(alpha)) + fabs(sin(beta) * sin(gamma)))) +
                pow(c, 2) * (a * (fabs(cos(alpha) * sin(beta)) + fabs(cos(gamma) * sin(beta))) +
                             b * (fabs(sin(beta) * sin(alpha)) + fabs(sin(beta) * sin(gamma)))) +
                pow(a, 2) * c *
                    (fabs(cos(beta) * cos(gamma) * sin(alpha) + cos(alpha) * sin(gamma)) +
                     fabs(cos(gamma) * sin(alpha) + cos(beta) * cos(alpha) * sin(gamma))) +
                pow(b, 2) * c *
                    (fabs(cos(beta) * cos(gamma) * sin(alpha) + cos(alpha) * sin(gamma)) +
                     fabs(cos(gamma) * sin(alpha) + cos(beta) * cos(alpha) * sin(gamma))) +
                2 * a * b * c * fabs(cos(beta) * cos(alpha) * cos(gamma) - sin(alpha) * sin(gamma)) +
                2 * a * b * c * fabs(cos(alpha) * cos(gamma) - cos(beta) * sin(alpha) * sin(gamma)));
    }

private:
    const double m_length;
    const double m_width;
};

#endif
