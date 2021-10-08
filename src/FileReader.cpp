#include "FileReader.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

FileReader::FileReader(const std::string& fileName, char delimiter, char comment) :
    m_file(fileName), m_delimiter(delimiter), m_comment(comment) {

    if (!m_file.is_open()) {
        throw std::runtime_error("File " + fileName + " does not exist");
    }
}

FileReader::FileReader(char delimiter, char comment) :
    m_file(""), m_delimiter(delimiter), m_comment(comment) {}

FileReader::~FileReader() { m_file.close(); }

std::vector<double> FileReader::split(const std::string& string) {
    std::stringstream stringStream;
    stringStream.str(string);
    std::string item;
    std::vector<double> columns;

    while (std::getline(stringStream, item, m_delimiter)) {
        columns.push_back(std::stod(item));
    }

    return columns;
}

namespace {

bool isSectionHeading(const std::string& line) { return line.rfind("[", 0) == 0; }

bool isComment(const std::string& line, char comment) { return line.rfind(comment, 0) == 0; }

} // namespace

bool FileReader::getLine(std::istream& file, std::string& line) {

    while (getline(file, line)) {
        if (line.empty() || isComment(line, m_comment)) continue;
        return true;
    }

    return false;
}

bool FileReader::getLine(std::string& line) { return getLine(m_file, line); }

std::vector<std::vector<double>> FileReader::getSectionLines(std::istream& file) {

    std::vector<std::vector<double>> lines;
    std::string line;
    int currentPosition = file.tellg();

    while (getLine(file, line)) {
        if (isSectionHeading(line)) {
            // Un-read the header line
            file.seekg(currentPosition, std::ios_base::beg);
            break;
        }
        lines.push_back(split(line));
        currentPosition = file.tellg();
    }

    return lines;
}

std::vector<std::vector<double>> FileReader::getSectionLines() { return getSectionLines(m_file); }

bool FileReader::getSectionHeading(std::istream& file, std::string& heading) {
    std::string line;
    if (getLine(file, line)) {
        const auto startPosition = line.find("[") + 1;
        const auto endPosition = line.find("]") - 1;

        heading = line.substr(startPosition, endPosition);
        std::transform(heading.begin(), heading.end(), heading.begin(), ::tolower);
        return !heading.empty();
    }

    return false;
}

bool FileReader::getSectionHeading(std::string& heading) { return getSectionHeading(m_file, heading); }