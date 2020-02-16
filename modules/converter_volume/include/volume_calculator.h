// Copyright 2019 Shakirov Ilya

#ifndef MODULES_CONVERTER_VOLUME_INCLUDE_VOLUME_CALCULATOR_H_
#define MODULES_CONVERTER_VOLUME_INCLUDE_VOLUME_CALCULATOR_H_

#include <string>

class VolumeCalculator {
 public:
     int degree(char * prefix);
    VolumeCalculator() = default;
    std::string operator()(int argc, const char** argv);
 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArgs(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double value, trans;
        char from, to;
        std::string operation;
    } Arguments;
};

#endif  // MODULES_CONVERTER_VOLUME_INCLUDE_VOLUME_CALCULATOR_H_
