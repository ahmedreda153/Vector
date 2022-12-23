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
#include "ASVector.h"
#include "ASVector.cpp"

using namespace std;

int main()
{
    ASVector<int> v(100);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    v.print();
    v.insert(v.begin() + 4, 5);
    v.print();
}