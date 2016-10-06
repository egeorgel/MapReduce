project(mapReduce_src)

set(HEADER_FILES
        Mapper.h
        Reducer.h
        StringComputer.h)

set(SOURCE_FILES
        Mapper.cpp
        Reducer.cpp
        StringComputer.cpp )

add_library(mapReduce_src STATIC ${SOURCE_FILES} ${HEADER_FILES})
