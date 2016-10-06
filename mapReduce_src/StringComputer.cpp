//
// Created by Edgar on 06/10/2016.
//
#include <regex>
#include <boost/tokenizer.hpp>
#include "StringComputer.h"

using namespace boost;

const StringComputer::type_numero2phraseS &StringComputer::get_computedStrings() const {
    return _computedStrings;
}

StringComputer::StringComputer(const std::string &sentences) {

    std::regex re("[.!?] ");
    std::sregex_token_iterator it(sentences.begin(), sentences.end(), re, -1);
    std::sregex_token_iterator reg_end;
    for (; it != reg_end; ++it) {
        _computedStrings.push_back({_computedStrings.size()+1, it->str()});
    }
}
