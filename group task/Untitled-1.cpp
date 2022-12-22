#include <bits/stdc++.h>
#include <vector>

using namespace std;

template <class T>
class ASVector
{
private:
    int size, capacity;
    T *data;
    typedef T *iterator;

public:
    ASVector(int cap = 2)
    {
        capacity = cap;
        size = 0;
        data = new T[capacity];
    }
    ASVector(T *arr, int n)
    {
        capacity = n;
        size = n;
        data = new T[capacity];
        for (int i = 0; i < n; i++)
        {
            data[i] = arr[i];
        }
    }
    ASVector(const ASVector &other)
    {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }
    }
    ~ASVector()
    {
        delete[] data;
    }
    ASVector &operator=(const T &other)
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
        }
    }
    ASVector &operator=(const T &&other)
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
            other.size = 0;
            other.capacity = 0;
            other.data = nullptr;
            return *this;
        }
        else
        {
            cout << "Cannot delete self" << endl;
        }
    }
    T &operator[](int indx)
    {
        if (indx > size - 1)
        {
            cout << "An error has occured, index out of range." << endl;
            exit(-1);
        }
        return data[indx];
    }
    int push_back(T item)
    {
        if (size < capacity)
        {
            data[size++] = item;
        }
        else
        {
            cout << "Resizing to " << capacity * 2 << endl;
            capacity *= 2;
            T *newdata = new T[capacity];

            for (int i = 0; i < size; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            newdata = nullptr;
            data[size++] = item;
        }
        return size;
    }
    T pop_back()
    {
        if (size < 1)
        {
            cout << "An error has occured, vector is empty." << endl;
            exit(-1);
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
    void erase(iterator it)
    {
        for (int i = it - data; i < size - 1; i++)
        {
            cout << it << endl;
            cout << data << endl;
            data[i] = data[i + 1];
        }
        size--;
    }
    void clear()
    {
        size = 0;
        delete[] data;
        data = new T[capacity];
    }
    iterator begin()
    {
        return data;
    }
    iterator end()
    {
        return data + size - 1;
    }
    bool operator==(const ASVector<T> &other)
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] != other.data[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator<(const ASVector<T> &other)
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
    int getSize() const
    {
        cout << "size: ";
        return size;
    }
    int getCapacity() const
    {
        return capacity;
    }
    int resize()
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
    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend ostream &operator<<(ostream &out, ASVector<T> vec)
    {
        for (int i = 0; i < vec.size; i++)
        {
            out << vec.data[i] << endl;
        }
        return out;
    }
};

int main()
{
    ASVector<string> vec(3);
    vec.push_back("hello");
    vec.push_back("world");
    vec.push_back("!");
    cout << vec << endl;
    vec.erase(vec.begin() + 1);
    cout << vec << endl;
}
