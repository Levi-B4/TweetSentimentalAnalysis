#include "dsstring.h"

#include <cstring>
#include <iostream>

// default constructor
DSString::DSString() {
    data = new char[1];
    data[0] = '\0';
}

// constructor - parameters: const char* otherData
DSString::DSString(const char* data) {
    this->data = new char[unsigned(strlen(data)) + 1];

    std::memcpy(this->data, data, strlen(data));

    this->data[unsigned(strlen(data))] = '\0';
}

// constructor - parameters: const DSString otherData
DSString::DSString(const DSString &other){
    data = new char[other.size() + 1];

    std::memcpy(data, other.data, strlen(other.data));

    data[other.size()] = '\0';
}

// returns the location of the passed char - parameters: const char searchChar
int DSString::findChar(const char searchChar) const{
    for(int i = 0; data[i] != '\0'; i++){
        if(data[i] == searchChar){
            return i;
        }
    }
    return -1;
}

// returns the location of the numInstance instance of the passed char - parameters: const char searchChar, const int numInstance
int DSString::findChar(const char searchChar, const int numInstance) const{

    if(numInstance <= 0){
        return -1;
    }

    int currentInstances = 0;
    for(int i = 0; data[i] != '\0'; i++){
        if(data[i] == searchChar){
            currentInstances++;
            if(currentInstances == numInstance){
                return i;
            }
        }
    }
    return -1;
}

void DSString::deleteIndex(const int index){
    int newSize = size() - 1;
    char* tempData = new char[newSize + 1];
    tempData[newSize] = '\0';

    std::memcpy(tempData, data, index);
    std::strcpy(tempData + index, data + index + 1);

    delete[] data;
    data = tempData;
}

// default destructor
DSString::~DSString() {
    delete[] data;
}

DSString& DSString::operator=(const char* data){
    delete[] this->data;

    this->data = new char[unsigned(strlen(data)) + 1];

    std::memcpy(this->data, data, strlen(data));

    this->data[unsigned(strlen(data))] = '\0';

    return *this;
}

DSString& DSString::operator=(const DSString& other){
    delete[] data;

    data = new char[other.size() + 1];

    std::memcpy(data, other.data, strlen(other.data));

    data[other.size()] = '\0';

    return *this;
}

DSString& DSString::operator+=(const char* data){
    int newSize = unsigned(strlen(data)) + size() + 1;

    char* tempData = this->data;

    this->data = new char[newSize];
    this->data[0] = '\0';

    std::strcat(this->data, tempData);
    delete[] tempData;

    std::strcat(this->data, data);

    return *this;
}

DSString& DSString::operator+=(const char data){
    int oldSize = unsigned(strlen(this->data));
    char* oldData = this->data;

    this->data = new char[oldSize + 2];

    memcpy(this->data, oldData, oldSize);
    delete[] oldData;

    this->data[oldSize] = data;
    this->data[oldSize + 1] = '\0';

    return *this;
}

DSString& DSString::operator+=(const DSString& other){
    *this += other.c_str();

    return *this;
}

DSString DSString::operator+(const char* data) const{
    DSString result = *this;
    result += data;
    return result;
}

DSString DSString::operator+(const char data) const{
    DSString result = *this;
    result += data;
    return result;
}

DSString DSString::operator+(const DSString& data) const{
    DSString result = *this;
    result += data;
    return result;
}

/*
 * comparison operator: ==
 * parameter: const char* other
 */
bool DSString::operator==(const char* other) const{
    if(strcmp(data, other) == 0){
        return true;
    }
    return false;
}

/*
 * comparison operator: ==
 * parameter: const DDString& other
 */
bool DSString::operator==(const DSString& other) const{
    if(strcmp(data, other.data) == 0){
        return true;
    }
    return false;
}

/*
 * comparison operator: <
 * parameter: const char* other
 */
bool DSString::operator<(const char* other) const{
    if(strcmp(other, data) < 0){
        return true;
    }
    return false;
}

/*
 * comparison operator: <
 * parameter: const DDString& other
 */
bool DSString::operator<(const DSString& other) const{
    if(strcmp(other.data, data) < 0) {
        return true;
    }
    return false;
}

/*
 * comparison operator: >
 * parameter: const char* other
 */
bool DSString::operator>(const char* other) const{
    if(strcmp(other, data) > 0){
        return true;
    }
    return false;
}

/*
 * comparison operator: >
 * parameter: const DDString& other
 */
bool DSString::operator>(const DSString& other) const{
    if(strcmp(other.data, data) > 0) {
        return true;
    }
    return false;
}

/*
 * comparison operator: <=
 * parameter: const char* other
 */
bool DSString::operator<=(const char* other) const{
    if(strcmp(other, data) <= 0){
        return true;
    }
    return false;
}

/*
 * comparison operator: <=
 * parameter: const DDString& other
 */
bool DSString::operator<=(const DSString& other) const{
    if(strcmp(other.data, data) <= 0) {
        return true;
    }
    return false;
}

/*
 * comparison operator: >=
 * parameter: const char* other
 */
bool DSString::operator>=(const char* other) const{
    if(strcmp(other, data) >= 0){
        return true;
    }
    return false;
}

/*
 * comparison operator: >=
 * parameter: const DDString& other
 */
bool DSString::operator>=(const DSString& other) const{
    if(strcmp(other.data, data) >= 0) {
        return true;
    }
    return false;
}

char& DSString::operator[](const int index) const{
    return data[index];
}

int DSString::size() const{
    return unsigned(strlen(data));
}

// returns sub-string between the given indexes
DSString DSString::substring(int startingIndex, int len) const{
    // TODO: throw outOfBounds exception for startingIndex < 0 || startingIndex > size() - 1

    // if len is 0 return empty string
    if(len == 0){
        DSString output;
        return output;
    }

    // if negative count backwards from starting index, and reset len and starting index
    if(len < 0) {
        int endingIndex = startingIndex;
        startingIndex += len + 1;
        if(startingIndex < 0){
            startingIndex = 0;
        }
        len = endingIndex - startingIndex + 1;
    } else{
        // adjust len so that ending index is within string
        if((startingIndex + len) > size()){
            len = size() - startingIndex;
        }
    }

    // if startingIndex is last index, return empty string
    if(startingIndex == size() - 1){
        DSString output;
        return output;
    }

    char outputArray[len + 1];

    memcpy(&outputArray, data + startingIndex, len);
    outputArray[len] = '\0';

    DSString output(outputArray);

    return output;
}

// returns sub-string starting at the given index
DSString DSString::substring(int startingIndex) const{
    if(startingIndex > size() - 1){
        return "";
    }
    char outputArray[size()];

    memcpy(&outputArray, data + startingIndex, size());
    outputArray[size() - 1] = '\0';

    DSString output(outputArray);

    return output;
}

char* DSString::c_str() const{
    return data;
}

std::ostream& operator<<(std::ostream& stream, const DSString& theString){
    stream << theString.data;

    return stream;
}

std::istream& operator>>(std::istream& stream, DSString& theString){
    if(stream.good()){
        // change data to empty string if no content
        if(stream.eof()){
            theString = "";
            return stream;
        }

        char tempChar;
        char* tempArray = new char[999];
        int currentIndex;

        // itterate through each char of input adding to temp array
        for(currentIndex = 0; !stream.eof(); currentIndex++){
            stream.get(tempChar);
            if(tempChar == '\r'){
                continue;
            }
            if(tempChar == '\n'){
                break;
            }
            tempArray[currentIndex] = tempChar;
        }

        delete[] theString.data;
        theString.data = new char[currentIndex + 1];

        /// copy temp array to data
        memcpy(theString.data, tempArray, currentIndex);
        theString.data[currentIndex] = '\0';

        delete[] tempArray;
    }

    return stream;
}
