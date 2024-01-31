#ifndef DSVECTOR_H
#define DSVECTOR_H

template <class T>
class DSVector
{
    public:
        //default constructor - params: int resizeIncrement = 5
        DSVector(int resizeIncrement = 5);

        // constructor - params: DSVector<T>& other
        DSVector(const DSVector<T>& other);

        // getter - numIndexes
        int getNumIndexes();

        // setter - capacity
        void setCapacity(int capacity);
        // getter - capacity
        int getCapacity();

        // setter - resizeIncrement
        void setResizeIncrement(int resizeIncrement);
        // getter - resizeIncrement
        int getResizeIncrement();

        // adds element to back of data array - params: T newElement
        void pushBack(T newelement);

        // removes last element of data array
        void removeLast();

        // creates new vector with capacity equal to numIndexes
        void shrink();

        // returns the first element of data array
        T& front();

        // returns last element of data array
        T& back();

        // returns pointer to first element of data
        T* getData();


        // sets this to the passed in vector - params: const DSVector<T>& other
        DSVector<T>& operator=(const DSVector<T>& other);

        // returns and adds passed in vector to the end of this - params: const DSVector<T>& other
        DSVector<T>& operator+=(const DSVector<T>& other);

        // returns this vector added to the passed in vector - params: const DSVector<T>& other
        DSVector<T> operator+(const DSVector<T>& other) const;


        // returns true if passed in vector has the same values as data - params: const DSVector<T>& other
        bool operator==(const DSVector<T>& other) const;

        // returns true if passed in vector does not have the same values as data - params: const DSVector<T>& other
        bool operator!=(const DSVector<T>& other) const;

        // returns the value at the passed in index - params: const int index
        T operator[](const int index) const;

        // default destructor
        ~DSVector();

    private:
        T* data;
        int capacity;
        int numIndexes;
        int resizeIncrement;
};

// default constructor - params: int resizeIncrement = 5
template <class T>
DSVector<T>::DSVector(int resizeIncrement){
    this->resizeIncrement = resizeIncrement;
    numIndexes = 0;
    capacity = this->resizeIncrement;
    data = new T[capacity];
}

// constructor - params: DSVector<T>& other
template <class T>
DSVector<T>::DSVector(const DSVector<T>& other){
    numIndexes = other.numIndexes;
    capacity = other.capacity;
    resizeIncrement = other.resizeIncrement;
    data = new T[capacity];

    // copy contents of other to this
    for(int i = 0; i < numIndexes; i++){
        this->data[i] = other.data[i];
    }
}

// getter - numIndexes
template <class T>
int DSVector<T>::getNumIndexes(){
    return numIndexes;
}

// setter - capacity
template <class T>
void DSVector<T>::setCapacity(int capacity){
    this->capacity = capacity;

    //create new data with new capactity and delete old one
    T* oldData = data;
    data = new T[capacity];

    for(int i = 0; i < numIndexes; i++){
        data[i] = oldData[i];
    }

    delete[] oldData;
}

// getter - capacity
template <class T>
int DSVector<T>::getCapacity(){
    return capacity;
}

// setter - resizeIncrement (no data change till resize occurs)
template <class T>
void DSVector<T>::setResizeIncrement(int resizeIncrement){
    this->resizeIncrement = resizeIncrement;
}

// getter - resizeIncrement
template <class T>
int DSVector<T>::getResizeIncrement(){
    return resizeIncrement;
}


// adds element to back of data array - params: T newElement
template <class T>
void DSVector<T>::pushBack(T newElement){
    // expand data if needed
    if(numIndexes == capacity){
        capacity = numIndexes + resizeIncrement - (numIndexes % resizeIncrement);

        T* oldData = data;
        data = new T[capacity];

        for(int i = 0; i < numIndexes; i++){
            data[i] = oldData[i];
        }

        delete[] oldData;
    }

    data[numIndexes++] = newElement;

}

// removes last element of data array
template <class T>
void DSVector<T>::removeLast(){
    numIndexes--;
}

// creates new vector with capacity equal to numIndexes
template <class T>
void DSVector<T>::shrink(){
    capacity = numIndexes;
    T* oldData = data;
    data = new T[capacity];

    for(int i = 0; i < numIndexes; i++){
        data[i] = oldData[i];
    }

    delete[] oldData;
}

// returns the first element of data array
template <class T>
T& DSVector<T>::front(){
    return data[0];
}

// returns last element of data arary
template <class T>
T& DSVector<T>::back(){
    return data[numIndexes - 1];
}

// returns pointer to first element of data
template <class T>
T* DSVector<T>::getData(){
    return data;
}

// sets this to the passed in vector - params: const DSVector<T>& other
template <class T>
DSVector<T>& DSVector<T>::operator=(const DSVector<T>& other){
    delete[] data;

    numIndexes = other.numIndexes;
    capacity = other.capacity;
    resizeIncrement = other.resizeIncrement;

    data = new T[capacity];

    for(int i = 0; i < numIndexes; i++){
        this->data[i] = other.data[i];
    }

    return *this;
}

// returns and adds passed in vector to the end of this - params: const DSVector<T>& other
template <class T>
DSVector<T>& DSVector<T>::operator+=(const DSVector<T>& other){
    int oldSize = numIndexes;
    numIndexes += other.numIndexes;

    int newCap = numIndexes + resizeIncrement - (numIndexes % resizeIncrement);

    if(capacity >= newCap){
        for(int i = oldSize; i < numIndexes; i++){
            data[i] = other.data[i - oldSize];
        }
    }
    else {
        capacity = newCap;

        T* oldData = data;
        delete[] data;

        data = new T[newCap];

        for(int i = 0; i < oldSize; i++){
            data[i] = oldData[i];
        }

        delete[] oldData;

        for(int i = oldSize; i < numIndexes; i++){
            data[i] = other.data[i];
        }
    }

    return *this;
}

// returns this vector added to the passed in vector - params: const DSVector<T>& other
template <class T>
DSVector<T> DSVector<T>::operator+(const DSVector<T>& other) const{
    DSVector<T> result = *this;
    result += other;
    return result;
}

// returns true if passed in vector has the same values as data - params: const DSVector<T>& other
template <class T>
bool DSVector<T>::operator==(const DSVector<T>& other) const{
    if(numIndexes != other.numIndexes){
        return false;
    }

    for(int i = 0; i < numIndexes; i++){
        if(data[i] != other.data[i]){
            return false;
        }
    }

    return true;
}

// returns true if passed in vector does not have the same values as data - params: const DSVector<T>& other
template <class T>
bool DSVector<T>::operator!=(const DSVector<T>& other) const{
    return !(*this == other);
}

// returns the value at the passed in index - params: const int index
template <class T>
T DSVector<T>::operator[](const int index) const{
    return data[index];
}

// default destructor
template<class T>
DSVector<T>::~DSVector(){
    delete[] data;
}

#endif // DSVECTOR_H
