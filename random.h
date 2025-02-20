#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <stdexcept>
#include <fstream>

inline std::vector<unsigned char> GenerateCryptographicallySecureRandomNumber(size_t bytes) {
    std::vector<unsigned char> random_value(bytes);

#if defined(__linux__) || defined(__APPLE__)
    // Linux/macOS: Use /dev/urandom
    std::ifstream urandom("/dev/urandom", std::ios::binary);
    if (!urandom) {
        throw std::runtime_error("Failed to open /dev/urandom");
    }

    urandom.read(reinterpret_cast<char*>(random_value.data()), bytes);
    if (static_cast<size_t>(urandom.gcount()) != bytes) {
        throw std::runtime_error("Failed to read enough bytes from /dev/urandom");
    }
#else
    throw std::runtime_error("Unsupported platform");
#endif

    return random_value;
}

#endif // RANDOM_H
