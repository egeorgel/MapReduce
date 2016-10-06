#include <iostream>
#include "Mapper.h"
#include "Reducer.h"
#include "StringComputer.h"


int main() {

    std::string input = "Hadoop uses MapReduce. There is a Map phase. love big data love you. Like I love Map";

    StringComputer stringComputer(input);

    Mapper mapper;
    Mapper::type_mot2nombreS m_mot2nombreS;
    for (const auto &i_numero2string : stringComputer.get_computedStrings()) {
        m_mot2nombreS.splice(m_mot2nombreS.end(), mapper.compute(i_numero2string));
    }

    Reducer reducer;
    Reducer::type_mot2nombreS r_mot2nombreS = reducer.compute(m_mot2nombreS);

    for(const auto &i_mot2numero : r_mot2nombreS) {
        std::cout << i_mot2numero.first << " , " << i_mot2numero.second << std::endl;
    }

    return 0;
}