#include <bits/stdc++.h>
#include "A3_SheetPb2_20210018.h"

using namespace std;

variantOne::variantOne() : nCoins(23), humanPile(0), computerPile(0) {}

int variantOne::findGoodMove(int nCoins, int pcPile)
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

bool variantOne::isBadPosition(int nCoins, int pcPile)
{
    if (nCoins == 0)
        if (pcPile % 2 == 0)
            return true;
        else
            return false;
    return findGoodMove(nCoins, pcPile) == 0;
}

void variantOne::humanTurn()
{
    cout << "pick From 1 to 3: ";
    cin >> n;
    while (n < 1 || n > 3 || n > nCoins)
    {
        cout << "Wrong input\nPlease pick from 1 to 3 and less than the number of coins left: ";
        cin >> n;
    }
    humanPile += n;
    cout << "Human pile: " << humanPile << endl;
}

void variantOne::computerTurn()
{
    n = findGoodMove(nCoins, computerPile);
    if (!n)
        n = 1;
    cout << "Computer picks " << n << " coins\n";
    computerPile += n;
    cout << "Computer pile: " << computerPile << endl;
}

void variantOne::checkWinner()
{
    if (humanPile % 2 == 0)
    {
        cout << "Human wins\n";
    }
    else
    {
        cout << "Computer wins\n";
    }
}

void variantOne::game()
{
    while (nCoins > 0)
    {
        cout << "\nNumber of coins left: " << nCoins << endl;
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        if (whoseTurn == 1)
        {
            humanTurn();
        }
        else
        {
            computerTurn();
        }
        nCoins -= n;
        whoseTurn = (whoseTurn + 1) % 2;
    }
    checkWinner();
}

variantTwo::variantTwo()
{
    gamePiles[0] = 4;
    gamePiles[1] = 5;
    gamePiles[2] = 6;
    pile = 0;
}

pair<int, int> variantTwo::findGoodMove(int piles[3])
{
    for (int pile = 1; pile <= 3; pile++)
    {
        for (int n = 1; n <= 3; n++)
        {
            if (piles[pile - 1] >= n)
            {
                piles[pile - 1] -= n;
                if (isBadPosition(gamePiles))
                {
                    piles[pile - 1] += n;
                    return make_pair(pile, n);
                }
                piles[pile - 1] += n;
            }
        }
    }
    return make_pair(0, 0);
}

bool variantTwo::isBadPosition(int gamePiles[3])
{
    if ((gamePiles[0] == 0 && gamePiles[1] == 0 && gamePiles[2] == 1) || (gamePiles[0] == 0 && gamePiles[1] == 1 && gamePiles[2] == 0) || (gamePiles[0] == 1 && gamePiles[1] == 0 && gamePiles[2] == 0))
        return true;
    return findGoodMove(gamePiles) == make_pair(0, 0);
}

void variantTwo::humanTurn()
{
    cout << "Pick a pile: ";
    cin >> pile;
    while (pile < 1 || pile > 3 || gamePiles[pile - 1] == 0)
    {
        cout << "Wrong input\nPlease pick a pile with coins: ";
        cin >> pile;
    }
    cout << "Pick from 1 to 3: ";
    cin >> n;
    while (n < 1 || n > 3 || n > gamePiles[pile - 1])
    {
        cout << "Wrong input\nPlease pick from 1 to 3 and less than the number of coins left: ";
        cin >> n;
    }
}

void variantTwo::computerTurn()
{
    pair<int, int> pcChoice = findGoodMove(gamePiles);
    pile = pcChoice.first;
    n = pcChoice.second;
    if (pcChoice == make_pair(0, 0))
    {
        pile = 1;
        n = 1;
    }
}

void variantTwo::checkWinner()
{
    if (whoseTurn)
    {
        cout << "Human wins\n";
    }
    else
    {
        cout << "Computer wins\n";
    }
}

void variantTwo::game()
{
    while (gamePiles[0] > 0 || gamePiles[1] > 0 || gamePiles[2] > 0)
    {
        cout << "pile 1: " << gamePiles[0] << "\npile 2: " << gamePiles[1] << "\npile 3: " << gamePiles[2] << endl;
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        switch (whoseTurn)
        {
        case HUMAN:
            humanTurn();
            break;
        case COMPUTER:
            computerTurn();
            break;
        }
        gamePiles[pile - 1] -= n;
        cout << "Computer picks " << n << " coins from pile " << pile << endl;
        whoseTurn = (whoseTurn + 1) % 2;
    }
    checkWinner();
}