/**
 * @file ASVector.h
 * @author Ahmed Reda / Shrouk Tarek
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ASVECTOR_H
#define ASVECTOR_H

#pragma once

template <class T>

class ASVector
{
private:
    int size, capacity;
    T *data;
    typedef T *iterator;

public:
    ASVector(int cap = 2);
    ASVector(T *arr, int n);
    ASVector(const ASVector &other);
    ~ASVector();
    ASVector &operator=(const ASVector &other);
    ASVector &operator=(const ASVector &&other);
    T &operator[](int index);
    int push_back(T item);
    T pop_back();
    void erase(iterator it);
    void erase(iterator start, iterator end);
    void clear();
    void insert(iterator it, T value);
    iterator begin();
    iterator end();
    bool operator==(const ASVector<T> &other);
    bool operator<(const ASVector<T> &other);
    int getSize() const;
    int getCapacity() const;
    int resize();
    bool empty();
    void print();

    /*
    The friend function is work when all the code is implemented in one file
    but when we separate the code in two files the friend function is not work
    */

    // friend ostream &operator<<(ostream &out, ASVector<T> other)
    // {
    //     for (int i = 0; i < other.size; i++)
    //     {
    //         out << other.data[i] << endl;
    //     }
    //     return out;
    // }
};

#endif