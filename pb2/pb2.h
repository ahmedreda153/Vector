#ifndef NIMGAME_H
#define NIMGAME_H

#include <bits/stdc++.h>

using namespace std;

#define HUMAN 1
#define COMPUTER 0

class nimGame
{
    protected:
        int n;
        int whoseTurn;
    public:
        nimGame():n(0),whoseTurn(HUMAN){};
        virtual void humanTurn()=0;
        virtual void computerTurn()=0;
        virtual void checkWinner()=0;
        virtual void game()=0;
};

class variantOne : public nimGame
{
    private:
        int nCoins;
        int humanPile;
        int computerPile;
        int findGoodMove(int nCoins, int pcPile);
        bool isBadPosition(int nCoins, int pcPile);
    public:
        variantOne();
        void humanTurn();
        void computerTurn();
        void checkWinner();
        void game();
};

class variantTwo : public nimGame
{
    private:
        int gamePiles[3];
        int pile;
        pair<int,int> findGoodMove(int piles[3]);
        bool isBadPosition(int piles[3]);
    public:
        variantTwo();
        void humanTurn();
        void computerTurn();
        void checkWinner();
        void game();
};

#endif