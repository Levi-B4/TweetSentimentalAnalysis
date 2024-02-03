#include <iostream>

#include "tweetdatacleaner.h"
#include "DataStructures/dsstring.h"

using namespace std;

int main()
{
    DSString trainDataFileName = "./dev-train-data.csv";

    TweetDataCleaner cleaner(trainDataFileName);
    cleaner.cleanFile();
}
