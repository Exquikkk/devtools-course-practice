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

void VolumeCalculator::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a volume calculator application.\n" +
        "Please provide arguments in the following format:\n" +
        "  $ " + appname + " <value> <operation>\n" +
        "Value have to be a double-precision number, " +
        "and number operation is one of the following:\n" +
        "'Kiloliter_To_Liter',\n" +
        "'Kiloliter_To_Deciliters',\n" +
        "'Kiloliter_To_Centiliters',\n" +
        "'Kiloliter_To_Milliliter',\n" +
        "'Liter_To_Kiloliter',\n" +
        "'Liter_To_Deciliters',\n" +
        "'Liter_To_Centiliters',\n" +
        "'Liter_To_Milliliter',\n" +
        "'Deciliters_To_Kiloliter',\n" +
        "'Deciliters_To_Liter',\n" +
        "'Deciliters_To_Centiliters',\n" +
        "'Deciliters_To_Milliliter',\n" +
        "'Centiliters_To_Kiloliter',\n" +
        "'Centiliters_To_Kiloliter',\n" +
        "'Centiliters_To_Kiloliter',\n" +
        "'Centiliters_To_Liter',\n" +
        "'Centiliters_To_Deciliters',\n" +
        "'Centiliters_To_Milliliter',\n" +
        "'Milliliter_To_Kiloliter',\n" +
        "'Milliliter_To_Liter',\n" +
        "'Milliliter_To_Deciliters',\n" +
        "'Milliliter_To_Centiliters',\n";
}

static int converter_volume::convect(int val, char* from, char* to) {
    int fromd = 0, tod = 0;
    fromd = degree(from);
    tod = degree(to);
    double result = val * (pow(10, fromd - tod));
    return result;
}

bool VolumeCalculator::ValidateNumberOfArgs(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 3) {
        Help(argv[0], "ERROR: Should be 2 arguments.\n");
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

int degree(char * prefix) {
    if (strcmp(prefix, "Kiloliter") == 0)
        return 3;
    else if (strcmp(prefix, "Deciliter") == 0)
        return -1;
    else if (strcmp(prefix, "Liter") == 0)
        return -1;
    else if (strcmp(prefix, "Centiliter") == 0)
        return -1;
    else if (strcmp(prefix, "Milliliter") == 0)
        return -1;
    else
        throw std::string("Wrong operation format!");
}

std::string VolumeCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArgs(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[1]);
        args.from = atoi(argv[2]);
        args.to = atoi(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    message_ = stream.str();
    return message_;
}
