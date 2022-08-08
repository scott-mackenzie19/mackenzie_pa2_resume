//
// Created by dalla on 9/21/2021.
//

#include "rwFile.h"

rwFile::rwFile() {
    words = new DSVector<wordPage>;

}

rwFile::~rwFile() {
    delete words;

}

rwFile::rwFile(const rwFile &object) {
    words = new DSVector<wordPage> (*object.words);


}

rwFile &rwFile::operator=(const rwFile &arg) {
    delete words;
    words = new DSVector<wordPage>(*arg.words);
    return *this;
}
#include <sstream>
void rwFile::loadVector(DSString& filename) {
    ifstream file;
    file.open(filename.c_str());
    if (file.is_open()) {
        cout << "File open" << endl;
    }
    char filler[100];
    file.getline(filler, 100, '<'); //stores to first thingy
    DSString fill;
    while (file.good()) {
        char throwaway[500];
        char pageNum[5];
        char pageContent[10000];
        DSString page;
        file.getline(pageNum, 4, '>'); //stores number as a dsstring
        file.getline(pageContent, 10000, '<'); //stores entire page
        page = pageNum;
        DSString pageContent2 = pageContent;
        int openindex;
        int closeindex;
        int nestopen;
        int nestclose;
        int nestlength = 0;
        int wordlength = 0;
        int numnests = 0; //variable tracks number of nests to insure nests are not lost
        int count = 0; //variable that tracks brackets, +1 for '[', -1 for ']'
        //cout << pageContent2 << endl;
        for (int i = 0; i < strlen(pageContent); i++) {
            if (pageContent2[i] == ']' && count == 1 && numnests == 0) {
                count--;
                closeindex = i;
                DSString query = pageContent2.substring(openindex + 1, wordlength );
                query.islower();
                wordPage word;
                word.setWord(query);
                word.setPage(page);
                words->push_back(word);
                wordlength = 0;
            }
            if (pageContent2[i] == ']' && count == 1 && numnests > 0) {
                count--;
                closeindex = i;
                DSString query = pageContent2.substring(openindex + 1, (wordlength - 2*numnests));
                query.islower();
                wordPage word;
                word.setWord(query);
                word.setPage(page);
                words->push_back(word);
                numnests = 0;
                wordlength = 0;
            }
            //cout << pageContent[i];
            if (count == 1) {
                wordlength++;
            }
            if (pageContent2[i] == '[' && count == 1) {
                count++;
                wordlength++;
                nestopen = i;
            }
            if (pageContent2[i] == ']' && count == 2) {

                    DSString query = pageContent2.substring(nestopen + 1, nestlength - 1);
                    query.islower();
                    wordPage word;
                    word.setWord(query);
                    word.setPage(page);
                    words->push_back(word);
                count--;

                nestclose = i;
                numnests++;
                wordlength++;
                nestlength = 0;

            }
            if (pageContent2[i] == '[' && count == 0) {
                count++;
                openindex = i;
            }
            if (count == 2) {
                nestlength++;
                wordlength++;
            }



        }
    }
}
          /*  char throwaway2[7000];
            char throwaway3[7000];
            char first[7000];
            char buffer[7000];
            char second[7000];
            wordPage newWord;
            ss.getline(throwaway2, 7000, '[');
            ff.getline(throwaway3, 7000, '['); //two copies of stream
            ss.getline(first, 7000, ']');
            ff.getline(second, 7000, '[');
            cout << "First : " << first << endl;
            cout << "Second : " << second << endl;
            if (strlen(first) < strlen(second)) {
                DSString temp;
                temp = first;
                newWord.setWord(temp.islower());
                newWord.setPage(page);
                words->push_back(newWord);
                ss.getline(first, 7000, '['); //caught up w each other
                ss.getline(first, 7000, '['); //caught up w each other
            }
            else if (strlen(first) > strlen(second)) { //when running into nested
                int count = 0;
                DSString holder;
                while ((strlen(first) > strlen(second))) {
                    wordPage tempWord;
                    strcpy(first, strcat(first, "]"));
                    DSString temp ;
                    DSString temp2;
                    temp = first; //string up to first nest obtained
                    ff.getline(second, 7000, ']'); //both streams now at same spot, nested term obtained
                    temp2 = second;
                    holder = temp + holder;
                    tempWord.setWord(temp2.islower());
                    tempWord.setPage(page);
                    words->push_back(tempWord);
                    ss.getline(first, 7000, ']'); //above algorithm checks for nested brackets
                    ff.getline(second, 7000, '[');
                    count++;
                }
                newWord.setWord(holder.islower());
                newWord.setPage(page);
                words->push_back(newWord);
            }
            //ss.getline(first, 7000, '['); //caught up w each other

        } */
       // cout << page << endl;
  //  }




void rwFile::print() {
    cout << words->getsize() << endl;
    for (int i = 0; i < 1; i++) {
        cout << i << endl;
        for(int j = 0; j < words[i].getsize() ; j++) {
            cout << words[i][j].getWord() << endl;
        }
        //cout << words->operator[](i).getWord() << endl;
    }
}

void rwFile::sortVector() {
    int i, j,imin;
    for ( i = 0; i < words->getsize() - 1 ; i++) {
        imin = i;
        for (j = i + 1; j < words->getsize(); j++) {
            if (strncmp(words[0][j].getWord().substring(0, 3).c_str() , words[0][imin].getWord().substring(0,3).c_str(), 3) < 0)  { //compares both strings
                imin = j;
            }

        } //implemented a selection sort
        wordPage temp = words[0][imin];
        words[0][imin] = words[0][i];
        words[0][i] = temp;


    }
   // for (int i= 0; i < words->getsize(); i++) {


  //  }


}

void rwFile::printToFile(DSString& filename) {
    DSString word[] = {"[", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
    ofstream ofs;
    ofs.open(filename.c_str());
    ofs.clear();
    for (int i = 0; i < 43; i++) {
        ofs << "[" << word[i]  << "]" << endl;
        for (int j = 0; j < words->getsize(); j++) {
            int f = 0;
            if (words[0][j].getWord()[f] == '[') {
                f = 1;

            }
            if (words[0][j].getWord()[f] == word[i][0]) {
                //ofs << "opened " << endl;
                ofs << words[0][j].getWord() << " " << words[0][j].getPage() << endl;
            }
        }
    }
    ofs.close();


}