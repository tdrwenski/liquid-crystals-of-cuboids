#ifndef __Config__
#define __Config__

#include "Cuboid.h"
#include "Spherocylinder.h"
#include "gsl/gsl_vector_double.h"
#include <algorithm>
#include <string>
#include <variant>

struct PackingFractions {
    double min;
    double max;
    double increment;
};

struct Indices {
    int l;
    int m;
    int n;
};

using ParticleModel_t = std::variant<Spherocylinder, Cuboid>;

class Config {
public:
    Config(const std::string& fileName, char delimiter);

public:
    const std::vector<ParticleModel_t>& getParticleModels() const { return m_particleModels; }
    const PackingFractions& getPackingFractions() const { return m_packingFractions; }
    int getDimension() const { return m_dimension; }
    const std::vector<Indices>& getIndices() const { return m_indices; }
    std::vector<gsl_vector*>& getStartingPoints() { return m_startingPoints; }

    int getLMax() const {
        return m_indices.empty()
                   ? 0
                   : std::max_element(m_indices.begin(), m_indices.end(),
                                      [](const auto& left, const auto& right) { return left.l < right.l; })
                         ->l;
    }

private:
    void setCuboidModels(const std::vector<std::vector<double>>& items);
    void setSpherocylinderModels(const std::vector<std::vector<double>>& items);
    void setPackingFractions(const std::vector<std::vector<double>>& items);
    void setDimension(const std::vector<std::vector<double>>& items);
    void setIndices(const std::vector<std::vector<double>>& items);
    void setStartGuess(const std::vector<std::vector<double>>& items);

private:
    std::vector<ParticleModel_t> m_particleModels;
    PackingFractions m_packingFractions;
    int m_dimension;
    std::vector<Indices> m_indices;
    int m_numberStartingPoints;
    std::vector<gsl_vector*> m_startingPoints;
};

#endif
