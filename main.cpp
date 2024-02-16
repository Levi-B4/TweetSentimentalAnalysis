#include "sentementalanalysis.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{


    SentementalAnalysis sentA(argv[1], argv[2], argv[3], argv[4], argv[5]);

    sentA.train();

    sentA.test();


    return 0;
}
