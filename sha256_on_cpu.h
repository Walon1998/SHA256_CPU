//
// Created by neville on 03.11.20.
//

#ifndef SHAONGPU_SHA256_ON_CPU_H
#define SHAONGPU_SHA256_ON_CPU_H

#include <cassert>
#include <string>
#include "sha256_padding.h"
#include "sha256_kernel_cpu.h"
#include <chrono>
#include <iostream>
#include <cmath
#include <fstream>

// return vector is currently passed by value, could be optimized
std::string sha256_on_cpu(const std::string &in, const bool benchmark = false) {

    // 1. Padding
    std::vector<uint32_t> padded = sha256_padding(in);

    // 2. Change byte ordering since SHA-256 uses big endian byte ordering
    // This is only necessary to get the same result as other implementations
    for (unsigned int &i : padded) {
        i = _byteswap_ulong(i);
    }

    // 2. Main Loop cpu
    std::vector<uint32_t> result(8);
    sha256_kernel_cpu(padded.data(), result.data(), padded.size());


    if (benchmark) {
        for (int i = 0; i < 10; i++) {
            sha256_kernel_cpu(padded.data(), result.data(), padded.size());
        }

        std::ofstream file("..//Result/CPU_" + std::to_string(in.size()) + ".txt");
        for (int i = 0; i < 100; i++) {
            auto start = std::chrono::high_resolution_clock::now();

            sha256_kernel_cpu(padded.data(), result.data(), padded.size());

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            file << duration.count() << std::endl;

        }

        file.close();

    }

    // 3. Convert Result to String
    std::string res_string;
    char buffer[50];
    for (int curr : result) {
        sprintf(buffer, "%x", curr);
        res_string += buffer;

    }
    return res_string;

}

void sha256_on_cpu_test() {

//    std::vector<std::string> vec = {"abc", "", "Neville", "Basil", "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"};

//    for(auto &i: vec){
//    std::cout << i << ": " << sha256_on_cpu(i) << std::endl;
//    }


    std::string out = sha256_on_cpu("abc");
    assert(out == "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");

    out = sha256_on_cpu("");
    assert(out == "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");

    out = sha256_on_cpu("Neville");
    assert(out == "359ef5c170178ca7309c92222e3a03707f03194eed16b262ab35536cbd72536f");

    out = sha256_on_cpu("Basil");
    assert(out == "a3ef49d473eec07b75d8a7a93a71b1f46b0b7573aa35e4789b7572c52acff793");

    out = sha256_on_cpu(
            "Der Begriff Secure Hash Algorithm (kurz SHA, englisch für sicherer Hash-Algorithmus) bezeichnet eine Gruppe standardisierter kryptologischer Hashfunktionen. Diese dienen zur Berechnung eines Prüfwerts für beliebige digitale Daten (Nachrichten) und sind unter anderem die Grundlage zur Erstellung einer digitalen Signatur.\n"
            "Der Prüfwert wird verwendet, um die Integrität einer Nachricht zu sichern. Wenn zwei Nachrichten den gleichen Prüfwert ergeben, soll die Gleichheit der Nachrichten nach normalem Ermessen garantiert sein, unbeschadet gezielter Manipulationsversuche an den Nachrichten. Darum fordert man von einer kryptologischen Hashfunktion die Eigenschaft der Kollisionssicherheit: es soll praktisch unmöglich sein, zwei verschiedene Nachrichten mit dem gleichen Prüfwert zu erzeugen. ");
    assert(out == "598ae7a5cd9e62a4b605063f1f353a82aeb75a854a35e322c710275ed3f82883");

    out = sha256_on_cpu("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
    assert(out == "cd372fb85148700fa88095e3492d3f9f5beb43e555e5ff26d95f5a6adc36f8e6");


}

void sha256_on_cpu_bench() {

    for (int i = 0; i < 8; i++) {
        std::cout << std::pow(10, i) << std::endl;
        sha256_on_cpu(std::string(std::pow(10, i), 'a'), true);
    }

}


#endif //SHAONGPU_SHA256_ON_GPU_H
