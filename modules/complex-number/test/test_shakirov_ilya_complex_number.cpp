// Copyright 2019 Shakirov Ilya

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shakirov_Ilya_ComplexNumberTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    ComplexNumber a;
    ComplexNumber b(25.0, 25.0);

    // Act&Assert
    EXPECT_ANY_THROW(b / a);
}

TEST(Shakirov_Ilya_ComplexNumberTest,
    Check_Correctness_Of_Two_Bool_Operations) {
    // Arrange
    ComplexNumber a(1.0, 2.5);
    ComplexNumber b(3.0, 4.0);
    ComplexNumber c, d;

    // Act
    c = a - b;
    d = a + b;

    // Assert
    ComplexNumber expected_ans(-2.0, -1.5);
    EXPECT_TRUE(expected_ans == c);
    EXPECT_TRUE(expected_ans != d);
}

TEST(Shakirov_Ilya_ComplexNumberTest, Test_Complex_Expression) {
    // Arrange
    ComplexNumber a(3.0, 2.0);
    ComplexNumber b(-3.0, 1.0);
    ComplexNumber c(2.0, 1.0);

    // Act
    ComplexNumber res = (a + b)* c;
    ComplexNumber simple(-3.0, 6.0);

    // Assert
    EXPECT_EQ(simple, res);
}

TEST(Shakirov_Ilya_ComplexNumberTest, Properly_Adds_Real_Numbers) {
    // Arrange
    ComplexNumber a(3.0, 0.0);
    ComplexNumber b(2.0, 0.0);
    ComplexNumber result;

    // Act
    result = a + b;

    // Assert
    EXPECT_TRUE(result.getRe() == 5.0 && result.getIm() == 0.0);
}

TEST(Shakirov_Ilya_ComplexNumberTest, Can_Assign_To_Himself) {
    // Arrange
    ComplexNumber c(-123.456, 78.999);

    // Act & Assert
    EXPECT_NO_THROW(c = c);
}
