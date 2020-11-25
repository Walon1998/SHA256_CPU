#include <cstdint>

#ifndef SHAONGPU_ROTR_CUH
#define SHAONGPU_ROTR_CUH

template<unsigned int N>
inline uint32_t ROTR(const uint32_t x) {
    return (x >> N) | (x << (32 - N));
}

#endif //SHAONGPU_ROTR_CUH
