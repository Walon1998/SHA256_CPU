
#ifndef SHAONGPU_SHR_CUH
#define SHAONGPU_SHR_CUH

#include <cstdint>

template<unsigned int N>
inline uint32_t SHR(const uint32_t x) {
    return x >> N;
}

#endif //SHAONGPU_ROTL_CUH
