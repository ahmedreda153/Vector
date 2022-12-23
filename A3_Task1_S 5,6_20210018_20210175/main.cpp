/**
 * @file main.cpp
 * @author Ahmed Reda / Shrouk Tarek
 * @brief
 * @version 0.1
 * @date 2022-12-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
#include "A3_Task1_S 5,6_20210018_20210175.h"
#include "A3_Task1_S 5,6_20210018_20210175.cpp"

using namespace std;

int main()
{
    try
    {

        // First test default constructor
        ASVector<int> v1(5);

        // Second test parameterized constructor
        int arr[] = {1, 2, 3, 4, 5};
        ASVector<int> v2(arr, 5);

        // Third test copy constructor
        ASVector<int> v3(v2);

        // Fourth test copy assignment operator
        ASVector<int> v4;
        v4 = v3;

        // Fifth test move assignment operator
        ASVector<int> v5;
        v5 = move(v4);

        // Sixth test operator[]
        cout << "v5[2] = " << v5[2] << endl;

        // Seventh test push_back
        v5.push_back(6);

        // Eighth test pop_back
        v5.pop_back();

        // Ninth test erase
        v5.erase(v5.begin() + 2);

        // Tenth test erase
        v5.erase(v5.begin(), v5.begin() + 2);

        // Eleventh test clear
        v4.clear();

        // Twelfth test insert
        v5.insert(v5.begin(), 1);

        // Thirteenth test begin
        cout << "v5.begin() = " << *v5.begin() << endl;

        // Fourteenth test end
        cout << "v5.end() = " << *v5.end() << endl;

        // Fifteenth test operator==
        if (v5 == v3)
        {
            cout << "v5 and v3 are equal" << endl;
        }
        else
        {
            cout << "v5 and v3 are not equal" << endl;
        }

        // Sixteenth test operator<
        if (v5 < v3)
        {
            cout << "v5 is less than v3" << endl;
        }
        else
        {
            cout << "v5 is not less than v3" << endl;
        }

        // Seventeenth test getSize
        cout << "v5 size = " << v5.getSize() << endl;

        // Eighteenth test getCapacity
        cout << "v5 capacity = " << v5.getCapacity() << endl;

        // Nineteenth test resize
        cout << "v5.capacity before resize = " << v5.getCapacity() << endl;
        v5.resize();
        cout << "v5.capacity after resize = " << v5.getCapacity() << endl;

        // Twentieth test empty
        if (v5.empty())
        {
            cout << "v5 is empty" << endl;
        }
        else
        {
            cout << "v5 is not empty" << endl;
        }

        // Twenty-first test print
        v5.print();
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
}