//
// Created by Edgar on 05/10/2016.
//

#include <boost/tokenizer.hpp>
#include "Mapper.h"

using namespace boost;

Mapper::type_mot2nombreS Mapper::compute(const Mapper::type_numero2phrase &numero2phrase) const {

    typedef tokenizer< char_separator<char> > tokenizer;

    char_separator<char> sep(" .,?!'");
    tokenizer tokens(numero2phrase.second, sep);

    type_mot2nombreS mot2nombreS;
    for ( const auto &i_token : tokens )
        mot2nombreS.push_back( {i_token, 1} );

    return mot2nombreS;
}
