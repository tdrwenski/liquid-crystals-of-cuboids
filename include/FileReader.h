#ifndef __FileReader__
#define __FileReader__

#include <fstream>
#include <vector>

class FileReader {
public:
    FileReader(const std::string& fileName, char delimiter, char comment = '#');
    ~FileReader();

public:
    std::vector<double> split(const std::string& string);
    bool getLine(std::string& line);
    std::vector<std::vector<double>> getSectionLines();
    bool getSectionHeading(std::string& heading);

protected:
    // For testing
    FileReader(char delimiter, char comment = '#');
    bool getLine(std::istream& file, std::string& line);
    std::vector<std::vector<double>> getSectionLines(std::istream& file);
    bool getSectionHeading(std::istream& file, std::string& heading);

private:
    std::ifstream m_file;
    char m_delimiter;
    char m_comment;
};

#endif
