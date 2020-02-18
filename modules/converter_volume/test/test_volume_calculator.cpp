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

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(LengthVolumeTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "two", "Milliliter", "Liter" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(LengthVolumeTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "1.0", "ryer", "Liter" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(LengthVolumeTest, Can_Centiliters_To_Milliliter) {
    vector<string> args = { "3.0", "Centiliter", "Milliliter" };

    Act(args);

    Assert("30");
}

TEST_F(LengthVolumeTest, Can_Milliliter_To_Deciliters) {
    vector<string> args = { "300.0", "Milliliter", "Deciliter" };

    Act(args);

    Assert("3");
}

TEST_F(LengthVolumeTest, Can_Milliliter_To_Centiliters) {
    vector<string> args = { "3.0", "Milliliter", "Centiliter" };

    Act(args);

    Assert("30");
}

TEST_F(LengthVolumeTest, Can_Milliliter_To_Liter) {
    vector<string> args = { "30.0", "Milliliter", "Liter" };

    Act(args);

    Assert("3");
}

TEST_F(LengthVolumeTest, Can_Milliliter_To_Kiloliter) {
    vector<string> args = { "300000.0", "Milliliter", "Kiloliter" };

    Act(args);

    Assert("3");
}

TEST_F(LengthVolumeTest, Can_Centiliters_To_Deciliters) {
    vector<string> args = { "3000.0", "Centiliter", "Deciliter" };

    Act(args);

    Assert("3");
}

TEST_F(LengthVolumeTest, Can_Centiliters_To_Liter) {
    vector<string> args = { "300.0", "Centiliter", "Liter" };

    Act(args);

    Assert("3");
}

TEST_F(LengthVolumeTest, Can_Centiliters_To_Kiloliter) {
    vector<string> args = { "3000000.0", "Centiliter", "Kiloliter" };

    Act(args);

    Assert("3");
}

TEST_F(LengthVolumeTest, Can_Deciliters_To_Milliliter) {
    vector<string> args = { "3.0", "Deciliter", "Milliliter" };

    Act(args);

    Assert("30000");
}

TEST_F(LengthVolumeTest, Can_Deciliters_To_Centiliters) {
    vector<string> args = { "3.0", "Deciliter", "Centiliter" };

    Act(args);

    Assert("3000");
}

TEST_F(LengthVolumeTest, Can_Deciliters_To_Liter) {
    vector<string> args = { "3.0", "Deciliter", "Liter" };

    Act(args);

    Assert("30");
}

TEST_F(LengthVolumeTest, Can_Deciliters_To_Kiloliter) {
    vector<string> args = { "3000.0", "Deciliter", "Kiloliter" };

    Act(args);

    Assert("3");
}

TEST_F(LengthVolumeTest, Can_Liter_To_Milliliter) {
    vector<string> args = { "3.0", "Liter", "Milliliter" };

    Act(args);

    Assert("3000");
}

TEST_F(LengthVolumeTest, Can_Liter_To_Centiliters) {
    vector<string> args = { "3.0", "Liter", "Centiliter" };

    Act(args);

    Assert("300");
}

TEST_F(LengthVolumeTest, Can_Liter_To_Deciliters) {
    vector<string> args = { "30.0", "Liter", "Deciliter" };

    Act(args);

    Assert("3");
}

TEST_F(LengthVolumeTest, Can_Liter_To_Kiloliter) {
    vector<string> args = { "300000.0", "Liter", "Kiloliter" };

    Act(args);

    Assert("3");
}

TEST_F(LengthVolumeTest, Can_Kiloliter_To_Milliliter) {
    vector<string> args = { "3.0", "Kiloliter", "Milliliter" };

    Act(args);

    Assert("30000000");
}

TEST_F(LengthVolumeTest, Can_Kiloliter_To_Centiliters) {
    vector<string> args = { "3.0", "Kiloliter", "Centiliter" };

    Act(args);

    Assert("3000000");
}

TEST_F(LengthVolumeTest, Can_Kiloliter_To_Deciliters) {
    vector<string> args = { "3.0", "Kiloliter", "Deciliter" };

    Act(args);

    Assert("3000");
}

TEST_F(LengthVolumeTest, Can_Kiloliter_To_Liter) {
    vector<string> args = { "3.0", "Kiloliter", "Liter" };

    Act(args);

    Assert("30000");
}
