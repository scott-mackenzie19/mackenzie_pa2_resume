//
// Created by dalla on 9/21/2021.
//

#include "wordPage.h"

wordPage::wordPage() {
    word = new DSString(nullptr); //new space with nullptr in constructor
    page = new DSString(nullptr);

}

wordPage::~wordPage() {
    delete word;
    delete page;

}

wordPage::wordPage(const wordPage &object) {
    word = new DSString(object.word->c_str());
    page = new DSString(object.page->c_str());

}

wordPage &wordPage::operator=(const wordPage &arg) {
    if (*word == *arg.word) {
        return *this;
    }
    delete page;
    delete word;
    page = new DSString(*arg.page);
    word = new DSString(*arg.word);
    return *this;

}

DSString wordPage::getWord() {
    return *word;
}

DSString wordPage::getPage() {
    return *page;
}

void wordPage::setWord(DSString &word1) {
    delete word;
    word = new DSString(word1);


}

void wordPage::setPage(DSString &word1) {
    delete page;
    page = new DSString(word1);

}

bool wordPage::operator>(const wordPage &arg) {
    if (this->getWord().c_str() > arg.word->c_str()) {
        return true;
    }
    else {
        return false;
    }
}
