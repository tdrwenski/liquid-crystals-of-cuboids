#include "FileReader.h"
#include <gtest/gtest.h>
#include <string>

namespace {

class TestFileReader : public FileReader {
public:
    TestFileReader(char delimiter) : FileReader(delimiter) {}

public:
    bool testGetLine(std::istream& file, std::string& line) { return getLine(file, line); }

    std::vector<std::vector<double>> testGetSectionLines(std::istream& file) { return getSectionLines(file); }

    bool testGetSectionHeading(std::istream& file, std::string& heading) {
        return getSectionHeading(file, heading);
    }
};

void assertVectorEquals(const std::vector<double>& observed, const std::vector<double>& expected) {
    EXPECT_EQ(observed.size(), expected.size());

    for (int i = 0; i < observed.size(); ++i) {
        EXPECT_EQ(observed[i], expected[i]);
    }
}

void assertVectorEquals(const std::vector<std::vector<double>>& observed,
                        const std::vector<std::vector<double>>& expected) {

    EXPECT_EQ(observed.size(), expected.size());

    for (int i = 0; i < observed.size(); ++i) {
        assertVectorEquals(observed[i], expected[i]);
    }
}

} // namespace

TEST(FileReader, shouldThrowIfFileNotFound) {

    try {
        FileReader fileReader("notAFileName", ',');
        FAIL() << "Expected exception";
    } catch (...) {
    }
}

TEST(FileReader, shouldGetLine) {

    const std::string expected = "10, 22, foo";
    std::istringstream file(expected + "\nbar\n");

    TestFileReader fileReader(',');
    std::string line;

    fileReader.testGetLine(file, line);
    EXPECT_EQ(line, expected);
}

TEST(FileReader, shouldSkipComments) {

    const std::vector<std::string> expected = {"10, 22, foo", "# a comment", "1, 2"};
    std::istringstream file(expected[0] + "\n" + expected[1] + "\n" + expected[2]);

    TestFileReader fileReader(',');
    std::string line;

    fileReader.testGetLine(file, line);
    EXPECT_EQ(line, expected[0]);

    fileReader.testGetLine(file, line);
    EXPECT_EQ(line, expected[2]);
}

TEST(FileReader, shouldGetLineAndSplitOnDelimiter) {

    std::istringstream file("10; 22\n");
    const std::vector<double> expected = {10, 22};

    TestFileReader fileReader(';');
    std::string line;
    fileReader.testGetLine(file, line);
    const std::vector<double> splitLine = fileReader.split(line);

    assertVectorEquals(splitLine, expected);
}

TEST(FileReader, shouldGetSectionHeading) {

    std::istringstream file("[foo]\n 10, 22\n");
    const std::string expected = "foo";

    TestFileReader fileReader(',');
    std::string heading;
    fileReader.testGetSectionHeading(file, heading);

    EXPECT_EQ(heading, expected);
}

TEST(FileReader, shouldGetSectionLines) {

    std::istringstream file("[foo]\n"
                            "1,2\n"
                            "3,4\n"
                            "[bar]\n"
                            "5,6");

    TestFileReader fileReader(',');
    std::string heading;

    std::string expectedHeading = "foo";
    std::vector<std::vector<double>> expected = {{1, 2}, {3, 4}};

    fileReader.testGetSectionHeading(file, heading);
    std::vector<std::vector<double>> observed = fileReader.testGetSectionLines(file);

    EXPECT_EQ(heading, expectedHeading);
    assertVectorEquals(observed, expected);

    expectedHeading = "bar";
    expected = {{5, 6}};

    fileReader.testGetSectionHeading(file, heading);
    observed = fileReader.testGetSectionLines(file);

    EXPECT_EQ(heading, expectedHeading);
    assertVectorEquals(observed, expected);
}