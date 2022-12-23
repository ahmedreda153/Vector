#include <bits/stdc++.h>

using namespace std;

template <typename T>

class Stack
{
private:
    T *arr;
    int size;
    int capacity;

public:
    Stack(int cap = 10);
    Stack(const Stack &other);
    Stack &operator=(const Stack &other);
    ~Stack();
    void push(T data);
    T pop();
    T top();
    int getSize();
    bool isEmpty();
    void manageStack();
};

class StackOverflowException
{
};

class StackEmptyException
{
};

template <typename T>
Stack<T>::Stack(int cap)
{
    capacity = cap;
    arr = new T[capacity];
    size = 0;
}

template <typename T>
Stack<T>::Stack(const Stack &other)
{
    size = other.size;
    capacity = other.capacity;
    arr = new T[capacity];
    for (int i = 0; i < other.size; i++)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack &other)
{
    if (this != &other)
    {
        delete[] arr;
        size = other.size;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < other.size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] arr;
}

template <typename T>
void Stack<T>::push(T data)
{
    if (size == capacity)
    {
        throw StackOverflowException();
    }
    arr[size] = data;
    size++;
}

template <typename T>
T Stack<T>::pop()
{
    if (size == 0)
    {
        throw StackEmptyException();
    }
    T data = arr[size - 1];
    size--;
    T *temp = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    temp = nullptr;
    return data;
}

template <typename T>
T Stack<T>::top()
{
    if (size == 0)
    {
        throw StackEmptyException();
    }
    return arr[size - 1];
}

template <typename T>
int Stack<T>::getSize()
{
    return size;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
void Stack<T>::manageStack()
{
    int choice;
    T data;
    while (true)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Size" << endl;
        cout << "5. Is Empty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        try
        {
            switch (choice)
            {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                push(data);
                break;
            case 2:
                cout << "Popped data: " << pop() << endl;
                break;
            case 3:
                cout << "Top data: " << top() << endl;
                break;
            case 4:
                cout << "Size: " << getSize() << endl;
                break;
            case 5:
                cout << "Is Empty: " << isEmpty() << endl;
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
                break;
            }
        }
        catch (StackOverflowException e)
        {
            cout << "Stack is full" << endl;
        }
        catch (StackEmptyException e)
        {
            cout << "Stack is empty" << endl;
        }
    }
}

int main()
{
    Stack<int> s(1);
    s.manageStack();
    return 0;
}