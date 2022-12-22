#include <bits/stdc++.h>
#include "ASVector.h"

using namespace std;

template <class T>
ASVector<T>::ASVector(int cap)
{
    capacity = cap;
    size = 0;
    data = new T[capacity];
}

template <class T>
ASVector<T>::ASVector(T *arr, int n)
{
    capacity = n;
    size = n;
    data = new T[capacity];
    for (int i = 0; i < n; i++)
    {
        data[i] = arr[i];
    }
}

template <class T>
ASVector<T>::ASVector(const ASVector &other)
{
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < other.size; i++)
    {
        data[i] = other.data[i];
    }
}

template <class T>
ASVector<T>::~ASVector()
{
    delete[] data;
}

template <class T>
ASVector<T> &ASVector<T>::operator=(const T &other)
{
    if (this != &other)
    {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }
        return *this;
    }
    else
    {
        cout << "Cannot delete self" << endl;
        return *this;
    }
}

template <class T>
ASVector<T> &ASVector<T>::operator=(const T &&other)
{
    if (this != &other)
    {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }
        return *this;
    }
    else
    {
        cout << "Cannot delete self" << endl;
        return *this;
    }
}

template <class T>
T &ASVector<T>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw "Index out of range";
    }
    else
    {
        return data[index];
    }
}

template <class T>
int ASVector<T>::push_back(T item)
{
    if (size == capacity)
    {
        resize();
    }
    data[size++] = item;
    return size;
}

template <class T>
T ASVector<T>::pop_back()
{
    if (size == 0)
    {
        throw "Vector is empty";
    }
    else
    {
        T temp = data[size - 1];
        size--;
        T *newdata = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        newdata = nullptr;
        return temp;
    }
}

template <class T>
void ASVector<T>::erase(iterator it)
{
    int index = it - data;
    if (index < 0 || index >= size)
    {
        throw "Index out of range";
    }
    else
    {
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
}

template <class T>
void ASVector<T>::erase(iterator start, iterator end)
{
    int start_index = start - data;
    int end_index = end - data;
    if (start_index < 0 || start_index >= size || end_index < 0 || end_index >= size || start_index > end_index)
    {
        throw "Index out of range";
    }
    else
    {
        for (int i = start_index; i < size - end_index + start_index; i++)
        {
            data[i] = data[i + (end_index - start_index)];
        }
        size -= end_index - start_index;
    }
}

template <class T>
void ASVector<T>::clear()
{
    size = 0;
    delete[] data;
    data = new T[capacity];
}

template <class T>
void ASVector<T>::insert(iterator it, T item)
{
    int index = it - data;
    if (index < 0 || index >= size)
    {
        throw "Index out of range";
    }
    else
    {
        if (size == capacity)
        {
            resize();
        }
        size++;
        for (int i = size; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = item;
    }
}

template <class T>
T *ASVector<T>::begin()
{
    return data;
}

template <class T>
T *ASVector<T>::end()
{
    return data + size - 1;
}

template <class T>
bool ASVector<T>::operator==(const ASVector<T> &other)
{
    if (size != other.size)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] != other.data[i])
            {
                return false;
            }
        }
        return true;
    }
}

template <class T>
bool ASVector<T>::operator<(const ASVector<T> &other)
{
    if (size != other.size)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] > other.data[i])
            {
                return false;
            }
            else if (data[i] < other.data[i])
            {
                return true;
            }
        }
        return true;
    }
}

template <class T>
int ASVector<T>::getSize() const
{
    return size;
}

template <class T>
int ASVector<T>::getCapacity() const
{
    return capacity;
}

template <class T>
int ASVector<T>::resize()
{
    capacity *= 2;
    T *newdata = new T[capacity];

    for (int i = 0; i < size; i++)
    {
        newdata[i] = data[i];
    }
    delete[] data;
    data = newdata;
    newdata = nullptr;
    return capacity;
}

template <class T>
bool ASVector<T>::empty()
{
    return size == 0;
}

template <class T>
void ASVector<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << endl;
    }
    cout << endl;
}
// template <class T>
// ostream &operator<<(ostream &out, ASVector<T> other)
// {
//     for (int i = 0; i < other.size(); i++)
//     {
//         out << other.data[i] << endl;
//     }
//     return out;
// }