//
// Created by Edgar on 05/10/2016.
//

#include "gtest/gtest.h"
#include "Mapper.h"

class MapperTest : public ::testing::Test {

protected:
   typedef Mapper::type_numero2phrase type_numero2phrase;
   typedef Mapper::type_mot2nombreS type_mot2nombreS;

public:
    virtual ~MapperTest() {}
};

TEST_F(MapperTest, mapperTest_Hadoop_uses_MapReduce){

    type_numero2phrase input{1, "Hadoop uses MapReduce."};
    type_mot2nombreS expect { {"Hadoop", 1}, {"uses", 1}, {"MapReduce", 1}};

    Mapper mapper;
    ASSERT_EQ(expect, mapper.compute(input));
}

TEST_F(MapperTest, mapperTest_There_is_a_Map_phase){

    type_numero2phrase input{1, "There is a Map phase"};
    type_mot2nombreS expect { {"There", 1}, {"is", 1}, {"a", 1}, {"Map", 1}, {"phase", 1}};

    Mapper mapper;
    ASSERT_EQ(expect, mapper.compute(input));
}

TEST_F(MapperTest, mapperTest_love_big_data_love_you){

    type_numero2phrase input{1, "love big data love you"};
    type_mot2nombreS expect { {"love", 1}, {"big", 1}, {"data", 1}, {"love", 1}, {"you", 1}};

    Mapper mapper;
    ASSERT_EQ(expect, mapper.compute(input));
}

TEST_F(MapperTest, mapperTest_There_is_a_Reduce_phase){

    type_numero2phrase input{1, "There is a Reduce phase"};
    type_mot2nombreS expect { {"There", 1}, {"is", 1}, {"a", 1}, {"Reduce", 1}, {"phase", 1}};

    Mapper mapper;
    ASSERT_EQ(expect, mapper.compute(input));
}
