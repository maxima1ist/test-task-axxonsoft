#include "src/line_counter.hpp"

#include <gtest/gtest.h>

TEST(line_counter, empty_file)
{
    ASSERT_EQ(traversing_directory("./tests/test0"), 0);
}

TEST(line_counter, only_file)
{
    ASSERT_EQ(traversing_directory("./tests/test1"), 45);
}

TEST(line_counter, general_case)
{
    ASSERT_EQ(traversing_directory("./tests/test2"), 307);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}