//
// Created by Edgar on 05/10/2016.
//

#ifndef MAPREDUCE_MAP_H
#define MAPREDUCE_MAP_H

#include <list>
#include <string>
#include <utility>

/*
 * Mapper
 * split a sentence into word
 */
class Mapper {

public:

    // key value - input
    typedef std::pair<unsigned, std::string> type_numero2phrase;
    typedef std::pair<std::string, unsigned> type_mot2nombre;

    // list mot,nombre(==1)
    typedef std::list<type_mot2nombre> type_mot2nombreS;

    /*
     * create a list of tuple (word, 1)
     */
    type_mot2nombreS compute(const type_numero2phrase &numero2phrase) const;
};


#endif //MAPREDUCE_MAP_H
