//
// Created by dalla on 9/21/2021.
//

#ifndef MACKENZIE_PA2_WORDPAGE_H
#define MACKENZIE_PA2_WORDPAGE_H
#include "DSString.h"

using namespace std;

class wordPage { //devised the name wordpage for class containing just that, word and page
private:
    DSString* word;
    DSString* page;
public:
    wordPage();
    ~wordPage();
    wordPage( const wordPage& object);
    wordPage& operator = (const wordPage& arg);
    bool operator > (const wordPage& arg);

    DSString getWord();
    DSString getPage();
    void setWord(DSString& word1);
    void setPage(DSString& word1);

};


#endif //MACKENZIE_PA2_WORDPAGE_H
