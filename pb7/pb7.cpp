#include <bits/stdc++.h>

using namespace std;

void clean(string &word, string &temp)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (ispunct(word[i]) && !isalnum(word[i]) && word[i] != '-')
        {
            continue;
        }
        else
        {
            temp += tolower(word[i]);
        }
    }
}

void checkMap(map<string, int> &m, string &temp)
{
    if (m[temp] == 0)
    {
        m[temp] = 1;
    }
    else
    {
        m[temp] += 1;
    }
}

void printMap(map<string, int> &m)
{
    cout << endl
         << left << setw(20) << "Key" << setw(10) << "Frequency" << endl
         << endl;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << left << setw(24) << i->first << setw(10) << i->second << endl;
    }
}

int main()
{
    map<string, int> m;
    fstream file;
    char fileName[70];
    cin.getline(fileName, 70); // there is a file for test, file name is (test.txt)
    file.open(fileName, ios::in);
    if (!file)
    {
        cout << "error";
        exit(0);
    }
    else
    {
        string word;
        string temp;
        while (file >> word)
        {
            temp = "";
            clean(word, temp);
            checkMap(m, temp);
        }
        printMap(m);
    }
}