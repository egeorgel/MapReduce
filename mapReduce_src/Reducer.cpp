//
// Created by Edgar on 05/10/2016.
//

#include <map>
#include "Reducer.h"

Reducer::type_mot2nombreS Reducer::compute(const Reducer::type_mot2nombreS &mot2nombreS) const {

    std::map<std::string, unsigned > map_mot2nombreS;

    for (const auto &mot2nombre : mot2nombreS){
        auto i_map = map_mot2nombreS.find(mot2nombre.first);
        if (i_map == map_mot2nombreS.end())
            map_mot2nombreS.insert(mot2nombre);
        else
            ++i_map->second;
    }

    return Reducer::type_mot2nombreS(map_mot2nombreS.begin(), map_mot2nombreS.end());
}
