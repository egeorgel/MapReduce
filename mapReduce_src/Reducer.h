//
// Created by Edgar on 05/10/2016.
//

#ifndef MAPREDUCE_REDUCER_H
#define MAPREDUCE_REDUCER_H

#include <list>
#include <string>
#include <utility>

/*
 * Reducer
 * count word occurrence
 */
class Reducer {

public:
    // key value - input
    typedef std::pair<std::string, unsigned> type_mot2nombre;

    // list mot,nombre(==n)
    typedef std::list<type_mot2nombre> type_mot2nombreS;

    /*
     * create a list of tuple (word, n)
     */
    type_mot2nombreS compute(const type_mot2nombreS &mot2nombreS) const;
};


#endif //MAPREDUCE_REDUCER_H
