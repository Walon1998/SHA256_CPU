//
// Created by nevil on 24.11.2020.
//

#include "ROTR.h"
#include "SHR.h"

#include <cstdint>

#ifndef SHA_ON_GPU_SIGMA_CUH
#define SHA_ON_GPU_SIGMA_CUH

 inline uint32_t sigma0(const uint32_t x) {
    return ROTR<7>(x) ^ ROTR<18>(x) ^ SHR<3>(x);
}

inline uint32_t sigma1(const uint32_t x) {
    return ROTR<17>(x) ^ ROTR<19>(x) ^ SHR<10>(x);
}

inline uint32_t Sigma1(const uint32_t x) {
    return ROTR<6>(x) ^ ROTR<11>(x) ^ ROTR<25>(x);
}

inline uint32_t Sigma0(const uint32_t x) {
    return ROTR<2>(x) ^ ROTR<13>(x) ^ ROTR<22>(x);
}


#endif //SHA_ON_GPU_SIGMA_CUH
