//
// Created by Edgar on 06/10/2016.
//

#include "gtest/gtest.h"
#include "Mapper.h"
#include "Reducer.h"
#include "StringComputer.h"

class MapReduceTest : public ::testing::Test {

public:
    virtual ~MapReduceTest() {}
};

TEST_F(MapReduceTest, mapperTest_Hadoop_uses_MapReduce){

    std::string input = "Hadoop uses MapReduce. There is a Map phase. love big data love you. Like I love Map";

    StringComputer stringComputer(input);

    Mapper mapper;
    Mapper::type_mot2nombreS m_mot2nombreS;
    for (const auto &i_numero2string : stringComputer.get_computedStrings()) {
        m_mot2nombreS.splice(m_mot2nombreS.end(), mapper.compute(i_numero2string));
    }

    Reducer reducer;
    Reducer::type_mot2nombreS result = reducer.compute(m_mot2nombreS);

    Reducer::type_mot2nombreS expect {
            {"Hadoop", 1},
            {"I", 1},
            {"Like", 1},
            {"Map", 2},
            {"MapReduce", 1},
            {"There", 1},
            {"a", 1},
            {"big", 1},
            {"data", 1},
            {"is", 1},
            {"love", 3},
            {"phase", 1},
            {"uses", 1},
            {"you", 1}
    };

    ASSERT_EQ(expect, result);
}