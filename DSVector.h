//
// Created by dalla on 9/15/2021.
//

#ifndef MACKENZIE_PA2_DSVECTOR_H
#define MACKENZIE_PA2_DSVECTOR_H
#include <iostream>
#include <sstream>
using namespace std;


template <typename DS>
class DSVector {
private:
    DS *arr; //pointer to whatever datatype
    int capacity; //capacity of vector
    int size; //number objects in vector

public:
    DSVector();

    explicit DSVector(const DS &item);

    DSVector<DS> &operator=(const DSVector<DS> &vec);

    DS & operator[](int) const;

    bool operator==(const DSVector<DS> &v);

    ~DSVector();

    void push_back(const DS &item);

    int getsize();

    int getcapacity();

    void sort1();


};


    template<typename DS>
    DSVector<DS>::DSVector() {
        size = 0;
        capacity = 10;
        arr = new DS[capacity];
    }
//new array created in default constructor

    template<typename DS>
    DSVector<DS>::DSVector(const DS & item) {
        size = 1;
        capacity = 10;
        arr = new DS[capacity];
        arr[0] = item;

    }

template<typename DS>
DSVector<DS>::~DSVector() {
    delete[] arr;
}

template<typename DS>
DSVector<DS> &DSVector<DS>::operator=(const DSVector<DS> & vec) {
    DS buffer[vec.capacity];
    buffer = *vec.arr;
    delete[] arr;
    arr = new DS[capacity];
    arr = buffer;
    capacity = vec.capacity;
    size = vec.size;
    return *this;
}

template<typename DS>
 DS & DSVector<DS>::operator[] (int index) const {
     if(!(index < 0 || index >= size)){
         return arr[index];
     }else{
       cout << "Index Out of Bounds" << endl;
       exit(0); //if attempting to reach index out of bounds, error message thrown
   }
    //else return value at index
}

template<typename DS>
bool DSVector<DS>::operator==(const DSVector<DS> & v) {
    if (size == v.size && capacity == v.capacity) {
        for (int i = 0; i < size; i++)
            if (arr[i] != v.arr[i])
                return false;
        return true;
    }
    return false;
}

template<typename DS>
void DSVector<DS>::push_back(const DS &item) {
    if (size == capacity) {
        DS* old = arr;
        arr = new DS[capacity = capacity * 2];
        copy(old, old + size, arr);
        delete[] old;
    }  //check capacity first to see if size needs to be doubled or not
    arr[size++] = item;

}


template<typename DS>
int DSVector<DS>::getsize() {
    return size;
}

template<typename DS>
int DSVector<DS>::getcapacity() {
    return capacity;
}

template<typename DS>
void DSVector<DS>::sort1() {
    sort(arr, arr + size);

}


#endif //MACKENZIE_PA2_DSVECTOR_H
