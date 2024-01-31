#ifndef TWEETDATACLEANER_H
#define TWEETDATACLEANER_H

#include "DataStructures/dsstring.h"
#include "DataStructures/dsvector.h"

class TweetDataCleaner
{
    public:
        TweetDataCleaner(DSString dirtyFilePath);

        void cleanFile();

        DSString getCleanFilePath();

        ~TweetDataCleaner();

    private:
        DSVector<DSString*> tweets;
        DSString dirtyFilePath;
        DSString cleanFilePath;

        void trimTweet(DSString* tweet);
        void removeStopWords(DSString* tweet);
        void wordStemming(DSString* tweet);
};

#endif // TWEETDATACLEANER_H
