//
// Created by Edgar on 06/10/2016.
//

#ifndef MAPREDUCE_STRINGCOMPUTER_H
#define MAPREDUCE_STRINGCOMPUTER_H


#include <string>
#include <list>

/*
 * StringComputer
 * split a text into multiple line
 * (numberOfTheSentence, sentence)
 */
class StringComputer {

public:
    // output type send to mapper
    typedef std::pair<unsigned, std::string> type_numero2phrase;
    typedef std::list<type_numero2phrase> type_numero2phraseS;

    StringComputer(const std::string &sentences);

    const type_numero2phraseS &get_computedStrings() const;
private:
    type_numero2phraseS _computedStrings;

};


#endif //MAPREDUCE_STRINGCOMPUTER_H
