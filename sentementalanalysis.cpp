#include "sentementalanalysis.h"

#include <iostream>
#include <fstream>

SentementalAnalysis::SentementalAnalysis(char** files) {
    this->files = new DSString[5];

    for(int i = 0; i < 5; i++){
        this->files[i] = files[i];
    }

    loadDataFile(this->files[0]);

}

void SentementalAnalysis::train(){

}

void SentementalAnalysis::test(){

}

SentementalAnalysis::~SentementalAnalysis(){
    delete[] files;
}




SentementalAnalysis::loadDataFile(DSString filePath){

}
