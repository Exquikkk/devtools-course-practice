// Copyright 2019 Shakirov Ilya

#include <stdio.h>
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

std::string parseOperation(const char* arg) {
    std::string op;
    enum {
        Kiloliter_To_Liter = 1,
        Kiloliter_To_Deciliters,
        Kiloliter_To_Centiliters,
        Kiloliter_To_Milliliter,
        Liter_To_Kiloliter,
        Liter_To_Deciliters,
        Liter_To_Centiliters,
        Liter_To_Milliliter,
        Deciliters_To_Kiloliter,
        Deciliters_To_Liter,
        Deciliters_To_Centiliters,
        Deciliters_To_Milliliter,
        Centiliters_To_Kiloliter,
        Centiliters_To_Liter,
        Centiliters_To_Deciliters,
        Centiliters_To_Milliliter,
        Milliliter_To_Kiloliter,
        Milliliter_To_Liter,
        Milliliter_To_Deciliters,
        Milliliter_To_Centiliters,
    };

    if (strcmp(arg, "Kiloliter_To_Liter") == 0) {
        op = std::to_string(static_cast<int>(Kiloliter_To_Liter));
    } else if (strcmp(arg, "Kiloliter_To_Deciliters") == 0) {
        op = std::to_string(static_cast<int>(Kiloliter_To_Deciliters));
    } else if (strcmp(arg, "Kiloliter_To_Centiliters") == 0) {
        op = std::to_string(static_cast<int>(Kiloliter_To_Centiliters));
    } else if (strcmp(arg, "Kiloliter_To_Milliliter") == 0) {
        op = std::to_string(static_cast<int>(Kiloliter_To_Milliliter));
    } else if (strcmp(arg, "Liter_To_Kiloliter") == 0) {
        op = std::to_string(static_cast<int>(Liter_To_Kiloliter));
    } else if (strcmp(arg, "Liter_To_Deciliters") == 0) {
        op = std::to_string(static_cast<int>(Liter_To_Deciliters));
    } else if (strcmp(arg, "Liter_To_Centiliters") == 0) {
        op = std::to_string(static_cast<int>(Liter_To_Centiliters));
    } else if (strcmp(arg, "Liter_To_Milliliter") == 0) {
        op = std::to_string(static_cast<int>(Liter_To_Milliliter));
    } else if (strcmp(arg, "Deciliters_To_Kiloliter") == 0) {
        op = std::to_string(static_cast<int>(Deciliters_To_Kiloliter));
    } else if (strcmp(arg, "Deciliters_To_Liter") == 0) {
        op = std::to_string(static_cast<int>(Deciliters_To_Liter));
    } else if (strcmp(arg, "Deciliters_To_Centiliters") == 0) {
        op = std::to_string(static_cast<int>(Deciliters_To_Centiliters));
    } else if (strcmp(arg, "Deciliters_To_Milliliter") == 0) {
        op = std::to_string(static_cast<int>(Deciliters_To_Milliliter));
    } else if (strcmp(arg, "Centiliters_To_Kiloliter") == 0) {
        op = std::to_string(static_cast<int>(Centiliters_To_Kiloliter));
    } else if (strcmp(arg, "Centiliters_To_Liter") == 0) {
        op = std::to_string(static_cast<int>(Centiliters_To_Liter));
    } else if (strcmp(arg, "Centiliters_To_Deciliters") == 0) {
        op = std::to_string(static_cast<int>(Centiliters_To_Deciliters));
    } else if (strcmp(arg, "Centiliters_To_Milliliter") == 0) {
        op = std::to_string(static_cast<int>(Centiliters_To_Milliliter));
    } else if (strcmp(arg, "Milliliter_To_Kiloliter") == 0) {
        op = std::to_string(static_cast<int>(Milliliter_To_Kiloliter));
    } else if (strcmp(arg, "Milliliter_To_Liter") == 0) {
        op = std::to_string(static_cast<int>(Milliliter_To_Liter));
    } else if (strcmp(arg, "Milliliter_To_Deciliters") == 0) {
        op = std::to_string(static_cast<int>(Milliliter_To_Deciliters));
    } else if (strcmp(arg, "Milliliter_To_Centiliters") == 0) {
        op = std::to_string(static_cast<int>(Milliliter_To_Centiliters));
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string VolumeCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArgs(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[1]);
        args.operation = parseOperation(argv[2]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    if (args.operation == "1") {
    double trans = converter_volume::KiloliterinMilliliter(args.value);
        stream << "Liter: " << converter_volume::MilliliterinLiter(trans);
    } else if (args.operation == "2") {
        double trans = converter_volume::KiloliterinMilliliter(args.value);
        stream << "Deciliters: " << converter_volume::
            MilliliterinDeciliters(trans);
    } else if (args.operation == "3") {
        double trans = converter_volume::KiloliterinMilliliter(args.value);
        stream << "Centiliters: " << converter_volume::
            MilliliterinCentiliters(trans);
    } else if (args.operation == "4") {
        stream << "Milliliter: " << converter_volume::
            KiloliterinMilliliter(args.value);
    } else if (args.operation == "5") {
        double trans = converter_volume::LiterinMilliliter(args.value);
        stream << "Kiloliter: " << converter_volume::
            MilliliterinKiloliter(trans);
    } else if (args.operation == "6") {
        double trans = converter_volume::LiterinMilliliter(args.value);
        stream << "Deciliters: " << converter_volume::
            MilliliterinDeciliters(trans);
    } else if (args.operation == "7") {
        double trans = converter_volume::LiterinMilliliter(args.value);
        stream << "Centiliters: " << converter_volume::
            MilliliterinCentiliters(trans);
    } else if (args.operation == "8") {
        stream << "Milliliter: " << converter_volume::
            LiterinMilliliter(args.value);
    } else if (args.operation == "9") {
        double trans = converter_volume::DecilitersinMilliliter(args.value);
        stream << "Kiloliter: ";
        stream << converter_volume::MilliliterinKiloliter(trans);
    } else if (args.operation == "10") {
        double trans = converter_volume::DecilitersinMilliliter(args.value);
        stream << "Liter: " << converter_volume::
            MilliliterinLiter(trans);
    } else if (args.operation == "11") {
        double trans = converter_volume::DecilitersinMilliliter(args.value);
        stream << "Centiliters: " << converter_volume::
            MilliliterinCentiliters(trans);
    } else if (args.operation == "12") {
        stream << "Milliliter: " << converter_volume::
            DecilitersinMilliliter(args.value);
    } else if (args.operation == "13") {
        double trans = converter_volume::CentilitersinMilliliter(args.value);
        stream << "Kiloliter: ";
        stream << converter_volume::MilliliterinKiloliter(trans);
    } else if (args.operation == "14") {
        double trans = converter_volume::CentilitersinMilliliter(args.value);
        stream << "Liter: " << converter_volume::
            MilliliterinLiter(trans);
    } else if (args.operation == "15") {
        double trans = converter_volume::CentilitersinMilliliter(args.value);
        stream << "Deciliters: " << converter_volume::
            MilliliterinDeciliters(trans);
    } else if (args.operation == "16") {
        stream << "Milliliter: " << converter_volume::
            CentilitersinMilliliter(args.value);
    } else if (args.operation == "17") {
        stream << "Kiloliter: " << converter_volume::
            MilliliterinKiloliter(args.value);
    } else if (args.operation == "18") {
        stream << "Liter: " << converter_volume::
            MilliliterinLiter(args.value);
    } else if (args.operation == "19") {
        stream << "Deciliters: ";
        stream << converter_volume::MilliliterinDeciliters(args.value);
    } else if (args.operation == "20") {
        stream << "Centiliters: " << converter_volume::
            MilliliterinCentiliters(args.value);
    }
    message_ = stream.str();
    return message_;
}
