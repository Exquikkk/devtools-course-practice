// Copyright 2019 Shakirov Ilya

#include <gtest/gtest.h>
#include "include/converter_volume.h"

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Create_Volume) {
    // Act & Assert
    ASSERT_NO_THROW(converter_volume a);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Milliliter_To_Centiliters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = converter_volume::MilliliterinCentiliters(input);

    // Assert
    EXPECT_NEAR(0.3, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Milliliter_To_Deciliters) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = converter_volume::MilliliterinDeciliters(input);

    // Assert
    EXPECT_NEAR(0.03, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Milliliter_To_Liter) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = converter_volume::MilliliterinLiter(input);

    // Assert
    EXPECT_NEAR(0.003, output, 0.001);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Milliliter_To_Kiloliter) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = converter_volume::MilliliterinKiloliter(input);

    // Assert
    EXPECT_NEAR(0.000003, output, 0.000001);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Centiliters_To_Milliliter) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = converter_volume::CentilitersinMilliliter(input);

    // Assert
    EXPECT_NEAR(30.0, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Centiliters_To_Deciliters) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::CentilitersinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinDeciliters(trans);

    // Assert
    EXPECT_NEAR(0.3, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Centiliters_To_Liter) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::CentilitersinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinLiter(trans);

    // Assert
    EXPECT_NEAR(0.03, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Centiliters_To_Kiloliter) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::CentilitersinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinKiloliter(trans);

    // Assert
    EXPECT_NEAR(0.00003, output, 0.00001);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Deciliters_To_Milliliter) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = converter_volume::DecilitersinMilliliter(input);

    // Assert
    EXPECT_NEAR(300.0, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Deciliters_To_Centiliters) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::DecilitersinMilliliter(input);
    // Act
    output = converter_volume::MilliliterinCentiliters(trans);

    // Assert
    EXPECT_NEAR(30.0, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Deciliters_To_Liter) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::DecilitersinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinLiter(trans);

    // Assert
    EXPECT_NEAR(0.3, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Deciliters_To_Kiloliter) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::DecilitersinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinKiloliter(trans);

    // Assert
    EXPECT_NEAR(0.0003, output, 0.00001);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Liter_To_Milliliter) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = converter_volume::LiterinMilliliter(input);

    // Assert
    EXPECT_NEAR(3000.0, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Liter_To_Centiliters) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::LiterinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinCentiliters(trans);

    // Assert
    EXPECT_NEAR(300.0, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Liter_To_Deciliters) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::LiterinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinDeciliters(trans);

    // Assert
    EXPECT_NEAR(30.0, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Liter_To_Kiloliter) {
    // Arrange
    double input = 300.0;
    double output;
    double trans = converter_volume::LiterinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinKiloliter(trans);

    // Assert
    EXPECT_NEAR(3.0, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Kiloliter_To_Milliliter) {
    // Arrange
    double input = 3.0;
    double output;

    // Act
    output = converter_volume::KiloliterinMilliliter(input);

    // Assert
    EXPECT_NEAR(3000000.0, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Kiloliter_To_Centiliters) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::KiloliterinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinCentiliters(trans);

    // Assert
    EXPECT_NEAR(300000.0, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Kiloliter_To_Deciliters) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::KiloliterinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinDeciliters(trans);

    // Assert
    EXPECT_NEAR(30000.0, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Kiloliter_To_Liter) {
    // Arrange
    double input = 3.0;
    double output;
    double trans = converter_volume::KiloliterinMilliliter(input);

    // Act
    output = converter_volume::MilliliterinLiter(trans);

    // Assert
    EXPECT_NEAR(300.0, output, 0.1);
}
