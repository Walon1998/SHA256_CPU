//
// Created by neville on 03.11.20.
//

#include <cstdint>

#ifndef SHAONGPU_CHOOSE_CUH
#define SHAONGPU_CHOOSE_CUH

inline  uint32_t ch(const uint32_t x, const uint32_t y, const uint32_t z) {

    return (x & y) ^ (~x & z);
}

#endif //SHAONGPU_CHOOSE_CUH
