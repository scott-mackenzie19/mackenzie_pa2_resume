//
// Created by dalla on 9/21/2021.
//

#ifndef MACKENZIE_PA2_RWFILE_H
#define MACKENZIE_PA2_RWFILE_H
#include "DSVector.h"
#include "wordPage.h"
#include <fstream>


class rwFile {
private:
    DSVector<wordPage>* words;
public:
    rwFile();
    ~rwFile();
    rwFile(const rwFile &object);
    rwFile& operator = (const rwFile& arg); //rule o' three

    void loadVector(DSString& filename);
    void print();
    void sortVector();
    void  printToFile(DSString& filename);


};


#endif //MACKENZIE_PA2_RWFILE_H
