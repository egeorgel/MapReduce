//
// Created by Edgar on 06/10/2016.
//

#include "gtest/gtest.h"
#include "StringComputer.h"

class StringComputerTest : public ::testing::Test {

protected:
    typedef StringComputer::type_numero2phraseS type_numero2phraseS;

public:
    virtual ~StringComputerTest() {}
};

TEST_F(StringComputerTest, stringComputerTest_dot){

    std::string input = "Hadoop uses MapReduce. There is a Map phase. love big data love you";
    type_numero2phraseS expect { {1, "Hadoop uses MapReduce"},
                                 {2, "There is a Map phase"},
                                 {3, "love big data love you"}};

    StringComputer stringComputer(input);
    ASSERT_EQ(expect, stringComputer.get_computedStrings());
}

TEST_F(StringComputerTest, stringComputerTest_other){

    std::string input = "Hadoop uses MapReduce! There is a Map phase. love big data love you? ";
    type_numero2phraseS expect { {1, "Hadoop uses MapReduce"},
                                 {2, "There is a Map phase"},
                                 {3, "love big data love you"}};

    StringComputer stringComputer(input);
    ASSERT_EQ(expect, stringComputer.get_computedStrings());
}