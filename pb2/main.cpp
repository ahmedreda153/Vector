#include <bits/stdc++.h>
#include "pb2.h"
#include "pb2.cpp"

using namespace std;

int main()
{
    int choice;
    while (true)
    {
        cout << "1. Variant 1" << endl;
        cout << "2. Variant 2" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            variantOne v1;
            v1.game();
            break;
        }
        case 2:
        {
            variantTwo v2;
            v2.game();
            break;
        }
        case 3:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}