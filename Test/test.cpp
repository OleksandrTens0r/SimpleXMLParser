//
// Created by Alex on 10/15/18.
//

#include <gtest/gtest.h>
#include "/Users/alex/Desktop/Task/Parser.h"

TEST(TestParser, test1)
{
   Parser parser;
   parser.parse("/Users/alex/Desktop/Task/testingFiles/additionForTest1.xml");
}

TEST(TestParser, test2)
{
    Parser parser;
    parser.parse("/Users/alex/Desktop/Task/testingFiles/additionForTest2.xml");
}

TEST(TestParser, test3)
{
    Parser parser;
    parser.parse("/Users/alex/Desktop/Task/testingFiles/additionForTest3.xml");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}