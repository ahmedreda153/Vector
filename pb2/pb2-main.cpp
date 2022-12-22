#include <bits/stdc++.h>

using namespace std;

bool isBadPosition(int nCoins, int pcPile);

int findGoodMove(int nCoins, int pcPile)
{
    for (int n = 1; n <= 3; n++)
    {
        if (nCoins - n < 0)
        {
            break;
        }
        if (isBadPosition(nCoins - n, pcPile + n))
            return n;
    }
    return 0;
}

bool isBadPosition(int nCoins, int pcPile)
{
    if (nCoins == 0)
        if (pcPile % 2 == 0)
            return true;
        else
            return false;
    return findGoodMove(nCoins, pcPile) == 0;
}

int main()
{
    int nCoins = 23, n;
    int whoseTurn = 1;
    int checkWin1 = 0, checkWin2 = 0;
    cout << "Welcome to Even Nim\nWe start the game with " << nCoins << "Coins" << endl;
    cout << "Each one picks 1 to 3 coins.\n";
    while (nCoins > 0)
    {
        cout << "\nNumber of coins left: " << nCoins << endl;
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        if (whoseTurn == 1)
        {
            cout << "Enter the number of coins you want to pick From 1 to 3: ";
            cin >> n;
            while (n < 1 || n > 3 || n > nCoins)
            {
                cout << "Wrong input, Please enter a number from 1 to 3 and less than the number of coins left: ";
                cin >> n;
            }
            checkWin1 += n;
            cout << "Human pile: " << checkWin1 << endl;
        }
        else
        {
            n = findGoodMove(nCoins, checkWin2);
            if (!n)
                n = 1;
            cout << "Computer picks " << n << " coins\n";
            checkWin2 += n;
            cout << "Computer pile: " << checkWin2 << endl;
        }
        nCoins -= n;
        whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "\n\nWinner is : " << (checkWin2 % 2 == 0 ? "Computer \n" : "Human \n");
}