// Copyright 2019 Shakirov Ilya

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/volume_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class LengthVolumeTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }
        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;
        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
 private:
    VolumeCalculator app_;
    string output_;
};

TEST_F(LengthVolumeTest, Can_Print_Advice_For_User_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a volume calculator application\\..*");
}

TEST_F(LengthVolumeTest, Can_Check_Number_Of_Arguments) {
    vector<string> args = { "5.5" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(LengthVolumeTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "two", "Milliliter_To_Liter" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(LengthVolumeTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "1.0", "garbage" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(LengthVolumeTest, Can_Centiliters_To_Milliliter) {
    vector<string> args = { "1", "Centiliters_To_Milliliter" };

    Act(args);

    Assert("Milliliter: 10");
}

TEST_F(LengthVolumeTest, Can_Milliliter_To_Deciliters) {
    vector<string> args = { "1", "Milliliter_To_Deciliters" };

    Act(args);

    Assert("Deciliters: 0.01");
}

TEST_F(LengthVolumeTest, Can_Milliliter_To_Centiliters) {
    vector<string> args = { "1", "Milliliter_To_Centiliters" };

    Act(args);

    Assert("Centiliters: 0.1");
}

TEST_F(LengthVolumeTest, Can_Milliliter_To_Liter) {
    vector<string> args = { "1.0", "Milliliter_To_Liter" };

    Act(args);

    Assert("Liter: 0.001");
}

TEST_F(LengthVolumeTest, Can_Milliliter_To_Kiloliter) {
    vector<string> args = { "1000.0", "Milliliter_To_Kiloliter" };

    Act(args);

    Assert("Kiloliter: 0.001");
}

TEST_F(LengthVolumeTest, Can_Centiliters_To_Deciliters) {
    vector<string> args = { "1.0", "Centiliters_To_Deciliters" };

    Act(args);

    Assert("Deciliters: 0.1");
}

TEST_F(LengthVolumeTest, Can_Centiliters_To_Liter) {
    vector<string> args = { "1", "Centiliters_To_Liter" };

    Act(args);

    Assert("Liter: 0.01");
}

TEST_F(LengthVolumeTest, Can_Centiliters_To_Kiloliter) {
    vector<string> args = { "100.0", "Centiliters_To_Kiloliter" };

    Act(args);

    Assert("Kiloliter: 0.001");
}

TEST_F(LengthVolumeTest, Can_Deciliters_To_Milliliter) {
    vector<string> args = { "1", "Deciliters_To_Milliliter" };

    Act(args);

    Assert("Milliliter: 100");
}

TEST_F(LengthVolumeTest, Can_Deciliters_To_Centiliters) {
    vector<string> args = { "1.0", "Deciliters_To_Centiliters" };

    Act(args);

    Assert("Centiliters: 10");
}

TEST_F(LengthVolumeTest, Can_Deciliters_To_Liter) {
    vector<string> args = { "1.0", "Deciliters_To_Liter" };

    Act(args);

    Assert("Liter: 0.1");
}

TEST_F(LengthVolumeTest, Can_Deciliters_To_Kiloliter) {
    vector<string> args = { "1.0", "Deciliters_To_Kiloliter" };

    Act(args);

    Assert("Kiloliter: 0.0001");
}

TEST_F(LengthVolumeTest, Can_Liter_To_Milliliter) {
    vector<string> args = { "1", "Liter_To_Milliliter" };

    Act(args);

    Assert("Milliliter: 1000");
}

TEST_F(LengthVolumeTest, Can_Liter_To_Centiliters) {
    vector<string> args = { "1", "Liter_To_Centiliters" };

    Act(args);

    Assert("Centiliters: 100");
}

TEST_F(LengthVolumeTest, Can_Liter_To_Deciliters) {
    vector<string> args = { "1", "Liter_To_Deciliters" };

    Act(args);

    Assert("Deciliters: 10");
}

TEST_F(LengthVolumeTest, Can_Liter_To_Kiloliter) {
    vector<string> args = { "300.0", "Liter_To_Kiloliter" };

    Act(args);

    Assert("Kiloliter: 0.3");
}

TEST_F(LengthVolumeTest, Can_Kiloliter_To_Milliliter) {
    vector<string> args = { "0.00001", "Kiloliter_To_Milliliter" };

    Act(args);

    Assert("Milliliter: 10");
}

TEST_F(LengthVolumeTest, Can_Kiloliter_To_Centiliters) {
    vector<string> args = { "1", "Kiloliter_To_Centiliters" };

    Act(args);

    Assert("Centiliters: 100000");
}

TEST_F(LengthVolumeTest, Can_Kiloliter_To_Deciliters) {
    vector<string> args = { "1", "Kiloliter_To_Deciliters" };

    Act(args);

    Assert("Deciliters: 10000");
}

TEST_F(LengthVolumeTest, Can_Kiloliter_To_Liter) {
    vector<string> args = { "1", "Kiloliter_To_Liter" };

    Act(args);

    Assert("Liter: 100");
}
