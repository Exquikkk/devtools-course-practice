// Copyright 2019 Shakirov Ilya

#include <iostream>

#include "include/volume_calculator.h"

int main(int argc, const char** argv) {
    VolumeCalculator app;
    std::cout << app(argc, argv);
    return 0;
}
