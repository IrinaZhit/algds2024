#include "lab1.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

const int EMPTY_STRING_DISTANCE = 7;
const int SAME_STRINGS_DISTANCE = 0;
const int DIFFERENT_STRINGS_DISTANCE = 3;

TEST(Distance, EmptyString_ReturnStringLength) {
    char x[] = "";
    char y[] = "abcdef";
    ASSERT_EQ(Distance(x, y), strlen(y));
    ASSERT_EQ(Distance(y, x), strlen(y));
}

TEST(Distance, SameStrings_ReturnZero) {
    char x[] = "love";
    char y[] = "love";
    ASSERT_EQ(Distance(x, y), SAME_STRINGS_DISTANCE);
}

TEST(Distance, DifferentStrings_ReturnValidDistance) {
    char x[] = "рtslddf";
    char y[] = "tsgldds";
    ASSERT_EQ(Distance(x, y), DIFFERENT_STRINGS_DISTANCE);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
