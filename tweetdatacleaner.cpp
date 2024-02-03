#include "tweetdatacleaner.h"

#include "DataStructures/dsstring.h"
#include "DataStructures/dsvector.h"

#include <fstream>

// constructor - params: DSString dirtyFilePath
TweetDataCleaner::TweetDataCleaner(DSString dirtyFilePath) {
    this->dirtyFilePath = dirtyFilePath;
    cleanFilePath = dirtyFilePath + ".clean";

    tweets.setCapacity(10000);
}

// intakes dirtyFile, processes data, outputs to cleanFile
void TweetDataCleaner::cleanFile() {
    std::ifstream dirtyFile(dirtyFilePath.c_str());
    std::ofstream cleanedFile(cleanFilePath.c_str());

    DSVector<char> currentTweetData(TWEET_CHAR_LIMIT + 1);
    DSVector<char> currentWord(20);
    char currentChar;

    DSString* name;
    DSString* tweet;
    DSString** input;

    int numCommas = 0;

    // skip first line
    DSString* trash = new DSString();
    dirtyFile >> *trash;
    delete trash;

    // itterate through each line cleaning then saving them to tweets vector
    //while(!dataFile.eof()){
    for(int L = 0;!dirtyFile.eof(); L++){
        dirtyFile.get(currentChar);
        if(L % 100000 == 0){
            std::cout << L << std::endl;
        }

        // make sure not empty line at end of file
        if(dirtyFile.eof()){
            break;
        }

        numCommas = 0;
        while(numCommas < 2){
            if(currentChar == ','){
                numCommas++;
            }
            dirtyFile.get(currentChar);
        }

        // get tweet name
        while(currentChar != ','){
            currentTweetData += currentChar;
            dirtyFile.get(currentChar);
        }
        currentTweetData += '\0';
        cleanedFile << currentTweetData.getData() << ',';
        currentTweetData.clear();

        // get and clean tweet content
        dirtyFile.get(currentChar);
        while(currentChar != '\n'){
            if(currentChar != ' '){
                // TODO: check if punctuation
                currentWord += currentChar;
            } else{
                // remove extra spaces; may just remove all repeats
                if(currentWord.getNumIndexes() == 0){
                    dirtyFile.get(currentChar);
                    continue;
                }

                // TODO: stem word

                // TODO: remove if stop word

                currentTweetData += ' ';
                currentTweetData += currentWord;
                currentWord.clear();
            }
            dirtyFile.get(currentChar);
        }
        currentTweetData += '\0';
        cleanedFile << currentTweetData.getData() << std::endl;
        currentTweetData.clear();
    }

    dirtyFile.close();
    cleanedFile.close();
}

// default destructor
TweetDataCleaner::~TweetDataCleaner(){

}

// returns true if word is in stop word list - params: const DSString& word
bool TweetDataCleaner::isStopWord(const DSString& word) const{
    return true;
}

// removes unnecessary parts of words - params: DSString* word
void TweetDataCleaner::stemWord(DSString* word) const{

}
