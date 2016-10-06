//
// Created by Edgar on 05/10/2016.
//

#include "gtest/gtest.h"
#include "Reducer.h"

class ReducerTest : public ::testing::Test {

protected:
    typedef Reducer::type_mot2nombreS type_mot2nombreS;

public:
    virtual ~ReducerTest() {}
};

TEST_F(ReducerTest, mapperTest_Hadoop_Hadoop_uses_MapReduce){

    type_mot2nombreS input{ {"Hadoop", 1}, {"Hadoop", 1}, {"uses", 1}, {"MapReduce", 1} };
    type_mot2nombreS expect { {"Hadoop", 2}, {"MapReduce", 1}, {"uses", 1} };

    Reducer reducer;
    ASSERT_EQ(expect, reducer.compute(input));
}

TEST_F(ReducerTest, mapperTest_There_is_a_Map_phase){

    type_mot2nombreS input{ {"There", 1}, {"is", 1}, {"a", 1}, {"Map", 1}, {"phase", 1} };
    type_mot2nombreS expect { {"Map", 1}, {"There", 1}, {"a", 1}, {"is", 1}, {"phase", 1} };

    Reducer reducer;
    ASSERT_EQ(expect, reducer.compute(input));
}

TEST_F(ReducerTest, mapperTest_There_is_a_Map_phase_Map_phase_Map){

    type_mot2nombreS input{ {"There", 1}, {"is", 1}, {"a", 1}, {"Map", 2}, {"phase", 1}, {"phase", 1}, {"Map", 1} };
    type_mot2nombreS expect { {"Map", 3}, {"There", 1}, {"a", 1}, {"is", 1}, {"phase", 2} };

    Reducer reducer;
    ASSERT_EQ(expect, reducer.compute(input));
}
