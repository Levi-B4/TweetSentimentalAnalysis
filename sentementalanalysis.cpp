#include "sentementalanalysis.h"

#include "DataStructures/dsstring.h"
#include "DataStructures/dsvector.h"

#include <iostream>
#include <fstream>

SentementalAnalysis::SentementalAnalysis(char* trainData, char* trainTarget, char* testData, char* testTarget, char* outputFile) {
    files[0] = trainData;
    files[1] = trainTarget;

    files[2] = testData;
    files[3] = testTarget;

    files[4] = outputFile;


    loadDataFile(files[0]);
}

void SentementalAnalysis::train(){

}

void SentementalAnalysis::test(){

}

SentementalAnalysis::~SentementalAnalysis(){

}




void SentementalAnalysis::loadDataFile(DSString filePath){

}
