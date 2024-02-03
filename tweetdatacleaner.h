#ifndef TWEETDATACLEANER_H
#define TWEETDATACLEANER_H

#include "DataStructures/dsstring.h"
#include "DataStructures/dsvector.h"

class TweetDataCleaner
{
    public:
        // constructor - params: DSString dirtyFilePath
        TweetDataCleaner(DSString dirtyFilePath);

        // intakes dirtyFile, processes data, outputs to cleanFile
        void cleanFile();

        // default destructor
        ~TweetDataCleaner();

    private:
        DSVector<DSString**> tweets;
        DSString dirtyFilePath;
        DSString cleanFilePath;
        int TWEET_CHAR_LIMIT = 280;

        // returns true if word is in stop word list - params: const DSString& word
        bool isStopWord(const DSString& word) const;

        // removes unnecessary parts of words - params: DSString* word
        void stemWord(DSString* word) const;

        // outputs data to cleanFile
        void saveCleanData();
};

#endif // TWEETDATACLEANER_H
