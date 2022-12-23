#include <bits/stdc++.h>
#include "ASVector.h"

using namespace std;

/**
 * @brief Construct a new ASVector<T>::ASVector object
 * 
 * @tparam T 
 * @param cap 
 */
template <class T>
ASVector<T>::ASVector(int cap)
{
    capacity = cap;
    size = 0;
    data = new T[capacity];
}

/**
 * @brief Construct a new ASVector<T>::ASVector object
 * 
 * @tparam T 
 * @param arr 
 * @param n 
 */
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

/**
 * @brief Construct a new ASVector<T>::ASVector object
 * 
 * @tparam T 
 * @param other 
 */
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

/**
 * @brief Destroy the ASVector<T>::ASVector object
 * 
 * @tparam T 
 */
template <class T>
ASVector<T>::~ASVector()
{
    delete[] data;
}

/**
 * @brief Overload the = operator (copy)
 * 
 * @tparam T 
 * @param other 
 * @return ASVector<T>& 
 */
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

/**
 * @brief Overload the = operator (move)
 * 
 * @tparam T 
 * @param other 
 * @return ASVector<T>& 
 */
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

/**
 * @brief overloading the [] operator
 * 
 * @tparam T 
 * @param index 
 * @return T& 
 */
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

/**
 * @brief add an element to the end of the vector
 * 
 * @tparam T 
 * @param item 
 * @return int 
 */
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

/**
 * @brief remove the last element of the vector
 * 
 * @tparam T 
 * @return T 
 */
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

/**
 * @brief erase an element at a given index
 * 
 * @tparam T 
 * @param it 
 */
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

/**
 * @brief erase a range of elements
 * 
 * @tparam T 
 * @param start 
 * @param end 
 */
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

/**
 * @brief remove all elements from the vector
 * 
 * @tparam T 
 */
template <class T>
void ASVector<T>::clear()
{
    size = 0;
    delete[] data;
    data = new T[capacity];
}

/**
 * @brief add an element at a given index
 * 
 * @tparam T 
 * @param it 
 * @param item 
 */
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

/**
 * @brief pointer to the first element
 * 
 * @tparam T 
 * @return T* 
 */
template <class T>
T *ASVector<T>::begin()
{
    return data;
}

/**
 * @brief pointer to the last element
 * 
 * @tparam T 
 * @return T* 
 */
template <class T>
T *ASVector<T>::end()
{
    return data + size - 1;
}

/**
 * @brief compare two vectors
 * 
 * @tparam T 
 * @param other 
 * @return true 
 * @return false 
 */
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

/**
 * @brief check if the first vector is less than the second vector
 * 
 * @tparam T 
 * @param other 
 * @return true 
 * @return false 
 */
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

/**
 * @brief return the size of the vector
 * 
 * @tparam T 
 * @return int 
 */
template <class T>
int ASVector<T>::getSize() const
{
    return size;
}

/**
 * @brief return the capacity of the vector
 * 
 * @tparam T 
 * @return int 
 */
template <class T>
int ASVector<T>::getCapacity() const
{
    return capacity;
}

/**
 * @brief resize the vector
 * 
 * @tparam T 
 * @return int 
 */
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

/**
 * @brief check if the vector is empty
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
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