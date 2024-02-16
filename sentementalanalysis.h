#ifndef SENTEMENTALANALYSIS_H
#define SENTEMENTALANALYSIS_H

#include "DataStructures/dsstring.h"
#include "DataStructures/dsvector.h"

class SentementalAnalysis
{
public:
    // constructor - params: char** files
    SentementalAnalysis(char* trainData, char* trainTarget, char* testData, char* testTarget, char* outputFile);

    // train classifier
    void train();

    // test classifier
    void test();

    ~SentementalAnalysis();

private:
    DSString files[5];

    void loadDataFile(DSString filePath);

};

#endif // SENTEMENTALANALYSIS_H
