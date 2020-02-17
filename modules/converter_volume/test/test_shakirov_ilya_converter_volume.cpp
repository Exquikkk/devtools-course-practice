// Copyright 2019 Shakirov Ilya

#include <gtest/gtest.h>
#include "include/converter_volume.h"

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Create_Volume) {
    // Act & Assert
    ASSERT_NO_THROW(converter_volume a);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Milliliter_To_Centiliters) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Milliliter", "Centiliter");

    // Assert
    EXPECT_NEAR(30.0, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Milliliter_To_Deciliters) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Milliliter", "Deciliter");

    // Assert
    EXPECT_NEAR(0.03, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Milliliter_To_Liter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Milliliter", "Liter");

    // Assert
    EXPECT_NEAR(0.3, output, 1.0);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Milliliter_To_Kiloliter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Milliliter", "Kiloliter");

    // Assert
    EXPECT_NEAR(0.000003, output, 10.0);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Centiliters_To_Milliliter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Centiliter", "Milliliter");

    // Assert
    EXPECT_NEAR(30.0, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Centiliters_To_Deciliters) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Centiliter", "Deciliter");

    // Assert
    EXPECT_NEAR(0.003, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Centiliters_To_Liter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Centiliter", "Liter");

    // Assert
    EXPECT_NEAR(0.03, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Centiliters_To_Kiloliter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Centiliter", "Kiloliter");

    // Assert
    EXPECT_NEAR(0.000003, output, 0.00001);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Deciliters_To_Milliliter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Deciliter", "Milliliter");

    // Assert
    EXPECT_NEAR(30000.0, output, 1.0);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Deciliters_To_Centiliters) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Deciliter", "Centiliter");

    // Assert
    EXPECT_NEAR(3000.0, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Deciliters_To_Liter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Deciliter", "Liter");

    // Assert
    EXPECT_NEAR(30.0, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Deciliters_To_Kiloliter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Deciliter", "Kiloliter");

    // Assert
    EXPECT_NEAR(0.0003, output, 0.001);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Liter_To_Milliliter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Liter", "Milliliter");

    // Assert
    EXPECT_NEAR(3000.0, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Liter_To_Centiliters) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Liter", "Centiliter");

    // Assert
    EXPECT_NEAR(300.0, output, 0.01);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Liter_To_Deciliters) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Liter", "Deciliter");

    // Assert
    EXPECT_NEAR(0.3, output, 1.0);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Liter_To_Kiloliter) {
    // Arrange
    converter_volume object;
    double input = 300.0;
    double output;

    // Act
    output = object.convect(input, "Liter", "Kiloliter");

    // Assert
    EXPECT_NEAR(0.0003, output, 0.001);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Kiloliter_To_Milliliter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Kiloliter", "Milliliter");

    // Assert
    EXPECT_NEAR(30000000.0, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Kiloliter_To_Centiliters) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Kiloliter", "Centiliter");

    // Assert
    EXPECT_NEAR(3000000.0, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Kiloliter_To_Deciliters) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Kiloliter", "Deciliter");

    // Assert
    EXPECT_NEAR(3000.0, output, 0.1);
}

TEST(Test_Shakirov_Ilya_Convector_Volume, Can_Kiloliter_To_Liter) {
    // Arrange
    converter_volume object;
    double input = 3.0;
    double output;

    // Act
    output = object.convect(input, "Kiloliter", "Liter");

    // Assert
    EXPECT_NEAR(30000.0, output, 0.1);
}
