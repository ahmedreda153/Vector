#include <bits/stdc++.h>

using namespace std;

#define SIZE 10

bool isValidPos(int maze[SIZE][SIZE], int x_axis, int y_axis)
{
    if (x_axis >= 0 && x_axis < SIZE && y_axis >= 0 && y_axis < SIZE && maze[x_axis][y_axis] == 1)
        return true;
    return false;
}

void storeAnswer(int solution[SIZE][SIZE], vector<vector<vector<int>>> &allSolutions)
{
    vector<vector<int>> temp;
    for (int i = 0; i < SIZE; i++)
    {
        temp.push_back(vector<int>());
        for (int j = 0; j < SIZE; j++)
            temp[i].push_back(solution[i][j]);
    }
    allSolutions.push_back(temp);
}

void solveMaze(int maze[SIZE][SIZE], int x_axis, int y_axis, int solution[SIZE][SIZE], vector<vector<vector<int>>> &allSolutions)
{
    if (x_axis == SIZE - 1 && y_axis == SIZE - 1)
    {
        solution[x_axis][y_axis] = 1;
        storeAnswer(solution, allSolutions);
        solution[x_axis][y_axis] = 0;
        return;
    }

    if (isValidPos(maze, x_axis + 1, y_axis))
        if (solution[x_axis + 1][y_axis] == 0)
        {
            solution[x_axis + 1][y_axis] = 1;
            solveMaze(maze, x_axis + 1, y_axis, solution, allSolutions);
            solution[x_axis + 1][y_axis] = 0;
        }
    if (isValidPos(maze, x_axis - 1, y_axis))
        if (solution[x_axis - 1][y_axis] == 0)
        {
            solution[x_axis - 1][y_axis] = 1;
            solveMaze(maze, x_axis - 1, y_axis, solution, allSolutions);
            solution[x_axis - 1][y_axis] = 0;
        }
    if (isValidPos(maze, x_axis, y_axis + 1))
        if (solution[x_axis][y_axis + 1] == 0)
        {
            solution[x_axis][y_axis + 1] = 1;
            solveMaze(maze, x_axis, y_axis + 1, solution, allSolutions);
            solution[x_axis][y_axis + 1] = 0;
        }
    if (isValidPos(maze, x_axis, y_axis - 1))
        if (solution[x_axis][y_axis - 1] == 0)
        {
            solution[x_axis][y_axis - 1] = 1;
            solveMaze(maze, x_axis, y_axis - 1, solution, allSolutions);
            solution[x_axis][y_axis - 1] = 0;
        }
}

void printAllSolutions(vector<vector<vector<int>>> &allSolutions)
{
    if (allSolutions.size() == 0)
    {
        cout << "Solution doesn't exist\n";
        return;
    }

    cout << "All solutions are:\n";
    for (int k = 0; k < allSolutions.size(); k++)
    {
        cout << "Solution " << k + 1 << ":\n";
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
                cout << allSolutions[k][i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
}

void shortestPath(vector<vector<vector<int>>> &allSolutions)
{
    if (allSolutions.size() == 0)
    {
        cout << "Solution doesn't exist\n";
        return;
    }

    int minimum = SIZE * SIZE;
    int index = 0;
    for (int k = 0; k < allSolutions.size(); k++)
    {
        int counter = 0;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (allSolutions[k][i][j] == 1)
                    counter++;
        if (counter < minimum)
        {
            minimum = counter;
            index = k;
        }
    }

    cout << "\nShortest path is:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << allSolutions[index][i][j] << " ";
        cout << endl;
    }
    cout << "Shortest path length is: " << minimum << endl;
}

void manager(int maze[SIZE][SIZE], vector<vector<vector<int>>> &allSolutions)
{
    int solution[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            solution[i][j] = 0;

    solution[0][0] = 1;
    solveMaze(maze, 0, 0, solution, allSolutions);
    printAllSolutions(allSolutions);
    shortestPath(allSolutions);
}

int main()
{
    int maze[SIZE][SIZE] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    vector<vector<vector<int>>> allSolutions;
    manager(maze, allSolutions);

    return 0;
}