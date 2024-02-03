#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>

class DSString
{
public:
    // default constructor
    DSString();
    // constructor - paramaters: const char* otherData
    DSString(const char* data);
    // constructor - paramaters: const DSString& otherData
    DSString(const DSString& other);

    // returns the location of the passed char - parameters: const char searchChar
    int findChar(const char searchChar) const;
    // returns the location of the numInstance instance of the passed char - parameters: const char searchChar, const int numInstance
    int findChar(const char searchChar, const int numInstance) const;

    void deleteIndex(const int index);

    // default destructor
    ~DSString();

    // assign operators
    DSString& operator=(const char* data);
    DSString& operator=(const DSString& other);

    DSString& operator+=(const char* data);
    DSString& operator+=(const char data);
    DSString& operator+=( const DSString& other);

    // concatination
    DSString operator+(const char* data) const;
    DSString operator+(const char data) const;
    DSString operator+(const DSString& data) const;

    // Comparison operators (check about making free functions instead)
    bool operator==(const char* other) const;
    bool operator==(const DSString& other) const;

    bool operator<(const char* other) const;
    bool operator<(const DSString& other) const;

    bool operator>(const char* other) const;
    bool operator>(const DSString& other) const;

    bool operator<=(const char* other) const;
    bool operator<=(const DSString& other) const;

    bool operator>=(const char* other) const;
    bool operator>=(const DSString& other) const;

    // index operator
    char& operator[](const int index) const;


    // returns size of data array
    int size() const;

    // returns sub-string between the given indexes
    DSString substring(int startingIndex, int len) const;
    // returns sub-string starting at the given index
    DSString substring(int startingIndex) const;

    char* c_str() const;

    //TODO: Error: causes error with catch.hpp
    //template <class U>
    friend std::ostream& operator<<(std::ostream& stream, const DSString& theString);

    //template <class U>
    friend std::istream& operator>>(std::istream& stream, DSString& theString);

private:
    char* data;
};

#endif // DSSTRING_H
