// Copyright 2019 Shakirov Ilya

#ifndef MODULES_CONVERTER_VOLUME_INCLUDE_CONVERTER_VOLUME_H_
#define MODULES_CONVERTER_VOLUME_INCLUDE_CONVERTER_VOLUME_H_

class converter_volume {
 public:
     static double CentilitersinMilliliter(const double &Centiliters) {
         return Centiliters * 10;
     }
     static double DecilitersinMilliliter(const double &Deciliters) {
         return Deciliters * 100;
     }
     static double LiterinMilliliter(const double &Liter) {
         return Liter * 1000;
     }
     static double KiloliterinMilliliter(const double &Kiloliter) {
         return Kiloliter * 1000000;
     }
     static double MilliliterinMilliliter(const double &Milliliter) {
         return Milliliter;
     }
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
};

#endif  // MODULES_CONVERTER_VOLUME_INCLUDE_CONVERTER_VOLUME_H_
