#include <iostream>
#include "ascii85.hpp"

int main(int argc, char* argv[]) {
    bool decodeMode = false;

    if (argc > 1 && std::strcmp(argv[1], "-d") == 0) {
        decodeMode = true;
    } else if (argc > 1 && std::strcmp(argv[1], "-e") == 0) {
        decodeMode = false;
    }

    try {
        std::vector<unsigned char> inputData;
        char ch;
        while (std::cin.get(ch)) {
            inputData.push_back(static_cast<unsigned char>(ch));
        }

        if (decodeMode) {
            std::vector<char> ascii85Data(inputData.begin(), inputData.end());
            Ascii85::decode(ascii85Data, std::cout);
        } else {
            Ascii85::encode(inputData, std::cout);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; 
    }

    return 0;
}