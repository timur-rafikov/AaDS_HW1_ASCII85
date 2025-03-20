#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <cmath>

class Ascii85 {
public:
    static void encode(const std::vector<unsigned char>& input, std::ostream& output) {
        std::size_t i = 0;
        while (i < input.size()) {
            std::vector<unsigned char> block(4, 0);
            std::size_t blockSize = 0;

            for (; blockSize < 4 && i < input.size(); ++blockSize, ++i) {
                block[blockSize] = input[i];
            }

            if (blockSize == 4 && block[0] == 0 && block[1] == 0 && block[2] == 0 && block[3] == 0) {
                output << 'z';  
            } else {
                unsigned long value = 0;
                for (std::size_t j = 0; j < 4; ++j) {
                    value |= static_cast<unsigned long>(block[j]) << (24 - 8 * j);
                }

                std::vector<char> encoded(5);
                for (int j = 4; j >= 0; --j) {
                    encoded[j] = static_cast<char>(value % 85 + '!');
                    value /= 85;
                }

                output.write(encoded.data(), blockSize + 1);
            }
        }
    }

    static void decode(const std::vector<char>& input, std::ostream& output) {
        std::size_t i = 0;
        while (i < input.size()) {
            if (input[i] == 'z') {
                output.write("\0\0\0\0", 4);
                ++i;
                continue;
            }

            std::vector<char> block(5, 'u');  
            std::size_t blockSize = 0;
            for (; blockSize < 5 && i < input.size(); ++blockSize, ++i) {
                if (input[i] < '!' || input[i] > 'u') {
                    throw std::runtime_error("Invalid ASCII85 character");
                }
                block[blockSize] = input[i];
            }

            if (blockSize < 5 && blockSize != 0) {
            	throw std::runtime_error("Incomplete ASCII85 block");
        	}

            unsigned long value = 0;
            for (std::size_t j = 0; j < 5; ++j) {
                value = value * 85 + (block[j] - '!');
            }

            std::vector<unsigned char> decoded(4);
            for (int j = 3; j >= 0; --j) {
                decoded[j] = static_cast<unsigned char>(value >> (24 - 8 * j));
            }

            output.write(reinterpret_cast<char*>(decoded.data()), blockSize - 1);
        }
    }
};