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

DSString& DSString::operator=(DSString& other){
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

DSString& DSString::operator+=(DSString& other){
    *this += other.c_str();

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

char& DSString::operator[](const int index){
    return data[index];
}

int DSString::size() const{
    return unsigned(strlen(data));
}

// returns sub-string between the given indexes
DSString DSString::substring(int startingIndex, int len){
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

char* DSString::c_str(){
    return data;
}

std::ostream& operator<<(std::ostream& stream, const DSString& theString){
    stream << theString.data;

    return stream;
}

std::istream& operator>>(std::istream& stream, DSString& theString){
    char * tempChar = theString.data;
    theString.data = new char[100];

    if(stream.good()){
        while(!stream.eof()){
            stream >> *theString.data;
        }
    }

    delete[] tempChar;
    return stream;
}
