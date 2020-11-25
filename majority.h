//
// Created by neville on 03.11.20.
//
#include <cstdint>

#ifndef SHAONGPU_MAJORITY_CUH
#define SHAONGPU_MAJORITY_CUH

inline uint32_t maj(const uint32_t x, const uint32_t y, const uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

#endif //SHAONGPU_MAJORITY_CUH
