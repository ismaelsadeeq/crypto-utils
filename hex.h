#ifndef HEX_H
#define HEX_H

#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

/**
 * @brief Converts a vector of bytes (unsigned char) into a hexadecimal string representation.
 *
 * @param data A vector containing the byte values.
 * @return A string representing the hexadecimal equivalent of the input data.
 */
std::string to_hex(const std::vector<unsigned char>& data) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0'); // Set output format to hex and pad with '0' if needed

    for (unsigned char c : data) {
        oss << std::setw(2) << static_cast<int>(c); // Convert each byte to a 2-character hex representation
    }
    return oss.str(); // Return the formatted hexadecimal string
}

/**
 * @brief Converts a hexadecimal string representation back to a vector of bytes.
 *
 * @param hex_str A string containing the hexadecimal representation.
 * @return A vector of unsigned char representing the original byte values.
 * @throws std::invalid_argument if the input string length is not even or contains invalid characters.
 */
std::vector<unsigned char> from_hex(const std::string& hex_str) {
    if (hex_str.size() % 2 != 0) {
        throw std::invalid_argument("Hex string length must be even.");
    }
    std::vector<unsigned char> bytes(hex_str.size() / 2);
    for (size_t i = 0; i < hex_str.size(); i += 2) {
        std::string byteString = hex_str.substr(i, 2); // Extract two-character hex substring
        int char_int = std::stoi(/*str=*/byteString, /*pos=*/nullptr, /*base=*/16); // Convert hex substring to an integer
        bytes.push_back(static_cast<unsigned char>(char_int)); // Store as byte
    }
    return bytes; // Return the vector of bytes
}

#endif // HEX_H
