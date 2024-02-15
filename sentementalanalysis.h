#ifndef SENTEMENTALANALYSIS_H
#define SENTEMENTALANALYSIS_H

class SentementalAnalysis
{
public:
    // constructor - params: char** files
    SentementalAnalysis(char** files);

    // train classifier
    void train();

    // test classifier
    void test();

    ~SentementalAnalysis();

private:
    DSString* files;

    void loadDataFile(DSString filePath);

};

#endif // SENTEMENTALANALYSIS_H
