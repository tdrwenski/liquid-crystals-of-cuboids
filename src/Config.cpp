#include "Config.h"
#include "Cuboid.h"
#include "FileReader.h"

#include <assert.h>
#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

enum class EHeading {
    cuboid,
    spherocylinder,
    packingFractions,
    dimension,
    indices,
    startGuess,
};

const std::map<std::string, EHeading> cHeadings = {
    {"cuboid dimensions", EHeading::cuboid},
    {"spherocylinder dimensions", EHeading::spherocylinder},
    {"packing fractions", EHeading::packingFractions},
    {"dimension", EHeading::dimension},
    {"indices", EHeading::indices},
    {"starting guess", EHeading::startGuess},
};

} // namespace

void Config::setCuboidModels(const std::vector<std::vector<double>>& items) {
    for (const auto& item : items) {
        assert(item.size() == 2);
        m_particleModels.push_back(ParticleModel_t(Cuboid(item[0], item[1])));
    }
}

void Config::setSpherocylinderModels(const std::vector<std::vector<double>>& items) {
    for (const auto& item : items) {
        assert(item.size() == 1);
        m_particleModels.push_back(ParticleModel_t(Spherocylinder(item[0])));
    }
}

void Config::setPackingFractions(const std::vector<std::vector<double>>& items) {
    assert(items.size() == 1);
    const auto item = items[0];
    assert(item.size() == 3);

    m_packingFractions = {item[0], item[1], item[2]};
}

void Config::setDimension(const std::vector<std::vector<double>>& items) {
    assert(items.size() == 1);
    const auto item = items[0];
    assert(item.size() == 1);

    m_dimension = item[0];
}

void Config::setIndices(const std::vector<std::vector<double>>& items) {
    assert(items.size() == m_dimension);
    for (const auto& item : items) {
        m_indices.push_back(
            {static_cast<int>(item.at(0)), static_cast<int>(item.at(1)), static_cast<int>(item.at(2))});
    }
}

void Config::setStartGuess(const std::vector<std::vector<double>>& items) {
    m_numberStartingPoints = items.size();

    for (const auto& item : items) {
        assert(item.size() == m_dimension);

        gsl_vector* pStartingPoint = gsl_vector_alloc(m_dimension);
        m_startingPoints.push_back(pStartingPoint);
        int iEquation = 0;

        for (const double& value : item) {
            gsl_vector_set(pStartingPoint, iEquation++, value);
        }
    }
}

Config::Config(const std::string& fileName, char delimiter) {

    FileReader fileReader(fileName, ',');
    std::string section;

    while (fileReader.getSectionHeading(section)) {
        const auto iterator = cHeadings.find(section);

        if (iterator == cHeadings.end()) {
            throw std::runtime_error("Unknown section heading: " + section + " in file " + fileName);
        }

        std::vector<std::vector<double>> items = fileReader.getSectionLines();

        switch (iterator->second) {
        case EHeading::cuboid: setCuboidModels(items); break;
        case EHeading::spherocylinder: setSpherocylinderModels(items); break;
        case EHeading::packingFractions: setPackingFractions(items); break;
        case EHeading::dimension: setDimension(items); break;
        case EHeading::indices: setIndices(items); break;
        case EHeading::startGuess: setStartGuess(items); break;
        }
    }
}
