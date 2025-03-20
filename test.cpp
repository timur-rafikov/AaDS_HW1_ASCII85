#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include "ascii85.hpp"  

TEST(Ascii85Test, EncodeEmptyInput) {
    std::vector<unsigned char> input;
    std::ostringstream output;
    Ascii85::encode(input, output);
    EXPECT_EQ(output.str(), "");
}

TEST(Ascii85Test, EncodeSingleBlock) {
    std::vector<unsigned char> input = {'h', 'e', 'l', 'l'};
    std::ostringstream output;
    Ascii85::encode(input, output);
    EXPECT_EQ(output.str(), "BOu!r");
}

TEST(Ascii85Test, EncodeZeroBlock) {
    std::vector<unsigned char> input = {0, 0, 0, 0};
    std::ostringstream output;
    Ascii85::encode(input, output);
    EXPECT_EQ(output.str(), "z");
}

TEST(Ascii85Test, EncodePartialBlock) {
    std::vector<unsigned char> input = {'h', 'e'};
    std::ostringstream output;
    Ascii85::encode(input, output);
    EXPECT_EQ(output.str(), "BOq");
}

TEST(Ascii85Test, DecodeEmptyInput) {
    std::vector<char> input;
    std::ostringstream output;
    Ascii85::decode(input, output);
    EXPECT_EQ(output.str(), "");
}

TEST(Ascii85Test, DecodeSingleBlock) {
    std::vector<char> input = {'B', 'O', 'u', '!', 'r'};
    std::ostringstream output;
    Ascii85::decode(input, output);
    EXPECT_EQ(output.str(), "hell");
}

TEST(Ascii85Test, DecodeZeroBlock) {
    std::vector<char> input = {'z'};
    std::ostringstream output;
    Ascii85::decode(input, output);
    EXPECT_EQ(output.str(), std::string(4, '\0'));
}

TEST(Ascii85Test, DecodeInvalidCharacter) {
    std::vector<char> input = {'B', 'O', 'u', '!', ' '};
    std::ostringstream output;
    EXPECT_THROW(Ascii85::decode(input, output), std::runtime_error);
}

TEST(Ascii85Test, DecodeIncompleteBlock) {
    std::vector<char> input = {'B'}; 
    std::ostringstream output;
    EXPECT_THROW(Ascii85::decode(input, output), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}