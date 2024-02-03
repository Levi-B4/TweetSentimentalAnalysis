#include <iostream>

#include "tweetdatacleaner.h"
#include "DataStructures/dsstring.h"

using namespace std;

int main(int argc, char* argv[])
{
    DSString trainDataFileName(argv[1]);

    TweetDataCleaner cleaner(trainDataFileName);

    cleaner.cleanFile();
}
