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

    // removes a char from the given index
    void deleteIndex(const int index);

    // default destructor
    ~DSString();

    // assignment operator - params: const char* data
    DSString& operator=(const char* data);
    // assignment operator - params: const DSString& other
    DSString& operator=(const DSString& other);

    // concatination operator - params: const char* data
    DSString operator+(const char* data) const;
    // concatination operator - params: const char data
    DSString operator+(const char data) const;
    // concatination operator - params: const DSString& data
    DSString operator+(const DSString& data) const;

    // assign/concat operator - params: const char* data
    DSString& operator+=(const char* data);
    // assign/concat operator - params: const char data
    DSString& operator+=(const char data);
    // assign/concat operator - params: const DSString& other
    DSString& operator+=( const DSString& other);

    // Comparison operator - params: const char* other
    bool operator==(const char* other) const;
    // Comparison operator - params: const DSString& other
    bool operator==(const DSString& other) const;

    // less than operator - params: const char* other
    bool operator<(const char* other) const;
    // less than operator - params: const DSString& other
    bool operator<(const DSString& other) const;

    // greater than operator - params: const char* other
    bool operator>(const char* other) const;
    // greater than operator - params: const DSString& other
    bool operator>(const DSString& other) const;

    // less than or equal operator - params: const char* other
    bool operator<=(const char* other) const;
    // less than or equal operator - params: const DSString& other
    bool operator<=(const DSString& other) const;

    // greater than or equal operator - params: const char* other
    bool operator>=(const char* other) const;
    // greater than or equal operator - params: const DSString& other
    bool operator>=(const DSString& other) const;

    // index operator - params: const int index
    char& operator[](const int index) const;


    // returns size of data array
    int size() const;

    // returns sub-string between the given indexes
    DSString substring(int startingIndex, int len) const;
    // returns sub-string starting at the given index
    DSString substring(int startingIndex) const;

    // returns data cstring
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
