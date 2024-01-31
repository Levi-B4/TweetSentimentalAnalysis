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

    // default destructor
    ~DSString();

    // assign operators
    DSString& operator=(const char* data);
    DSString& operator=(DSString& other);

    DSString& operator+=(const char* data);
    DSString& operator+=(DSString& other);

    DSString& operator+=(const char data);

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
    char& operator[](const int index);


    // returns size of data array
    int size() const;

    // returns sub-string between the given indexes
    DSString substring(int startingIndex, int size);

    char* c_str();

    //TODO: Error: causes error with catch.hpp
    //template <class U>
    friend std::ostream& operator<<(std::ostream& stream, const DSString& theString);

    //template <class U>
    friend std::istream& operator>>(std::istream& stream, DSString& theString);

private:
    char* data;
    char* begin;
    char* end;
};

std::ostream& operator<<(std::ostream& stream, const DSString& theString);
std::istream& operator>>(std::istream& stream, DSString& theString);



#endif // DSSTRING_H
