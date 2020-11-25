
#include <iostream>
#include "sha256_on_cpu.h"

int main() {
    sha256_on_cpu_test();
    sha256_on_cpu_bench();
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}