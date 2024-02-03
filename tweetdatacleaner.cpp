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
    std::ifstream dataFile(dirtyFilePath.c_str());

    DSVector<char> currentTweetData(TWEET_CHAR_LIMIT + 1);
    DSVector<char> currentWord(20);
    char currentChar;

    DSString* name;
    DSString* tweet;
    DSString** input;

    int numCommas = 0;

    // skip first line
    DSString* trash = new DSString();
    dataFile >> *trash;
    delete trash;

    // itterate through each line cleaning then saving them to tweets vector
    //while(!dataFile.eof()){
    for(int L = 0; !dataFile.eof(); L++){
        if(L % 10000 == 0){
            std::cout << L << std::endl;
        }
        dataFile.get(currentChar);

        // make sure not empty line at end of file
        if(dataFile.eof()){
            break;
        }

        numCommas = 0;
        while(numCommas < 2){
            if(currentChar == ','){
                numCommas++;
            }
            dataFile.get(currentChar);
        }

        // get tweet name
        while(currentChar != ','){
            currentTweetData += currentChar;
            dataFile.get(currentChar);
        }
        currentTweetData += '\0';
        name = new DSString(currentTweetData.getData());
        currentTweetData.clear();

        // get and clean tweet content
        dataFile.get(currentChar);
        while(currentChar != '\n'){
            if(currentChar != ' '){
                // TODO: check if punctuation
                currentWord += currentChar;
            } else{
                // remove extra spaces; may just remove all repeats
                if(currentWord.getNumIndexes() == 0){
                    dataFile.get(currentChar);
                    continue;
                }

                // TODO: stem word

                // TODO: remove if stop word

                currentTweetData += ' ';
                currentTweetData += currentWord;
                currentWord.clear();
            }
            dataFile.get(currentChar);
        }
        currentTweetData += '\0';
        tweet = new DSString(currentTweetData.getData());
        currentTweetData.clear();

        input = new DSString*[2];
        input[0] = name;
        input[1] = tweet;

        tweets.pushBack(input);
    }

    saveCleanData();
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

// outputs data to cleanFile
void TweetDataCleaner::saveCleanData(){
    std::ofstream cleanFile(cleanFilePath.c_str());

    for(int i = 0; i < tweets.getNumIndexes(); i++){
        cleanFile << *tweets[i][0] << "," << *tweets[i][1] << std::endl;
    }

    cleanFile.close();
}
