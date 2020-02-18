// Copyright 2019 Shakirov Ilya

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include "include/volume_calculator.h"
#include "include/converter_volume.h"

int degree(std::string prefix) {
    if (prefix == "Kiloliter")
        return 6;
    else if (prefix =="Deciliter")
        return 3;
    else if (prefix == "Liter")
        return 2;
    else if (prefix == "Centiliter")
        return 0;
    else if (prefix == "Milliliter")
        return -1;
    else
        throw std::string("Wrong operation format!");
}

int converter_volume::convect
(int val, std::string from, std::string to) {
    int fromd = 0, tod = 0;
    fromd = degree(from);
    tod = degree(to);
    double result = val * (pow(10, abs(fromd) - tod));
    return result;
}

void VolumeCalculator::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a volume calculator application.\n" +
        "Please provide arguments in the following format:\n" +
        "  $ " + appname + " <value> <operation>\n" +
        "Value have to be a double-precision number, " +
        "and number operation is one of the following:\n" +
        "'Kiloliter',\n" +
        "'Liter',\n" +
        "'Deciliter',\n" +
        "'Centiliter',\n" +
        "'Milliliter',\n";
}

bool VolumeCalculator::ValidateNumberOfArgs(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 3) {
        Help(argv[0], "ERROR: Should be 3 arguments.\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}

std::string VolumeCalculator::parseOperation(std::string arg) {
    Arguments args;
    std::string op = std::to_string(static_cast<int>
        (converter_volume::convect(args.value, args.from, args.to)));
    return op;
}

std::string VolumeCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArgs(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[1]);
        args.from = parseOperation(argv[2]);
        args.to = parseOperation(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    stream << converter_volume::convect(args.value, args.from, args.to);
    message_ = stream.str();
    return message_;
}
