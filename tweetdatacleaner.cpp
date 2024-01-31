#include "tweetdatacleaner.h"

TweetDataCleaner::TweetDataCleaner(DSString dirtyFilePath) {
    this->dirtyFilePath = dirtyFilePath;

    tweets.setCapacity(10000);
    cleanFile();
}

void TweetDataCleaner::cleanFile() {
    // read line
    // parse line
    // skip line[0]
}

DSString TweetDataCleaner::getCleanFilePath(){
    return cleanFilePath;
}

TweetDataCleaner::~TweetDataCleaner() {

}

void TweetDataCleaner::trimTweet(DSString* tweet) {
    // remove stop words
    // stemming words; take out prefixes and suffixes
}

void TweetDataCleaner::removeStopWords(DSString* tweet) {

}

void TweetDataCleaner::wordStemming(DSString* tweet) {

}
