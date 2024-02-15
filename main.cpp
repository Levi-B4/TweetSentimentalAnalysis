#include "sentementalanalysis.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    SentementalAnalysis sentA(argv);

    sentA.train();

    sentA.test();


    return 0;
}
