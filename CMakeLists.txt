cmake_minimum_required(VERSION 3.17)
project(sha256_bench_cpu)

set(CMAKE_CXX_STANDARD 11)
add_executable(sha256_bench_cpu main.cpp choose.h majority.h ROTR.h SHR.h sigma.h)