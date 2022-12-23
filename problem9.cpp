#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
template <class T>
class Set
{
private:
    vector<T> classV;

public:
    Set() {}
    void Add(T item)
    {

        if (find(classV.begin(), classV.end(), item) != classV.end())
        {
        }
        else
        {
            classV.push_back(item);
        }
    }
    void Remove(T item)
    {
        for (int i = 0; i < classV.size(); i++)
        {
            if (item == classV[i])
            {
                classV.erase(classV.begin() + i);
                break;
            }
        }
    }
    // void print()
    // {
    //     for (int i = 0; i < classV.size(); i++)
    //     {
    //         cout << classV[i] << endl;
    //     }
    //     cout << "------" << endl;
    // }
    int Numofitems()
    {
        int numofitems = classV.size();
        return numofitems;
    }
    bool check(T item)
    {
        if (find(classV.begin(), classV.end(), item) != classV.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Set<int> obj1;
    Set<double> obj2;
    Set<string> obj3;
    obj3.Add("alo");
    obj3.Add("hey");
    obj3.Add("what");
    obj3.Remove("what");
    // cout<<obj3.check("what");
    // cout<<obj3.Numofitems();
    // obj3.print();
}