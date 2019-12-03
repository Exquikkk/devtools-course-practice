// Copyright 2019 Shakirov Ilya

#ifndef MODULES_CONVERTER_VOLUME_INCLUDE_CONVERTER_VOLUME_H_
#define MODULES_CONVERTER_VOLUME_INCLUDE_CONVERTER_VOLUME_H_

class converter_volume {
 public:
    static double MilliliterinCentiliters(const double &Milliliter) {
        return Milliliter / 10;
    }
    static double MilliliterinDeciliters(const double &Milliliter) {
        return Milliliter / 100;
    }
    static double MilliliterinLiter(const double &Milliliter) {
        return Milliliter / 1000;
    }
    static double MilliliterinKiloliter(const double &Milliliter) {
        return Milliliter / 1000000;
    }
    static double CentilitersinMilliliter(const double &Centiliters) {
        return Centiliters * 10;
    }
    static double CentilitersinDeciliters(const double &Centiliters) {
        return Centiliters / 10;
    }
    static double CentilitersinLiter(const double &Centiliters) {
        return Centiliters / 1000;
    }
    static double CentilitersinKiloliter(const double &Centiliters) {
        return Centiliters / 100000;
    }
    static double DecilitersinMilliliter(const double &Deciliters) {
        return Deciliters * 100;
    }
    static double DecilitersinCentiliters(const double &Deciliters) {
        return Deciliters * 10;
    }
    static double DecilitersinLiter(const double &Deciliters) {
        return Deciliters /10;
    }
    static double DecilitersinKiloliter(const double &Deciliters) {
        return Deciliters / 10000;
    }
    static double LiterinMilliliter(const double &Liter) {
        return Liter * 1000;
    }
    static double LiterinCentiliters(const double &Liter) {
        return Liter * 100;
    }
    static double LiterinDeciliters(const double &Liter) {
        return Liter * 10;
    }
    static double LiterinKiloliter(const double &Liter) {
        return Liter / 10;
    }
    static double KiloliterinMilliliter(const double &Kiloliter) {
        return Kiloliter * 1000000;
    }
    static double KiloliterinCentiliters(const double &Kiloliter) {
        return Kiloliter * 100000;
    }
    static double KiloliterinDeciliters(const double &Kiloliter) {
        return Kiloliter * 10000;
    }
    static double KiloliterinLiter(const double &Kiloliter) {
        return Kiloliter * 100;
    }
};

#endif  // MODULES_CONVERTER_VOLUME_INCLUDE_CONVERTER_VOLUME_H_
