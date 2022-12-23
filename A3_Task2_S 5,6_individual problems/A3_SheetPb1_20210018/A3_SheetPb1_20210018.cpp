#include <bits/stdc++.h>

using namespace std;

void addSpaces(int index, string phrase, string store, vector<string> words, vector<string> &result)
{
    if (index == phrase.length())
    {
        result.push_back(store);
    }
    for (int i = index; i < phrase.length(); i++)
    {
        string temp = phrase.substr(index, i - index + 1);
        if (binary_search(words.begin(), words.end(), temp))
        {
            addSpaces(i + 1, phrase, store + temp + " ", words, result);
        }
    }
}

int main()
{
    fstream dictionary;
    dictionary.open("dictionary.txt", ios::in);
    vector<string> words;
    vector<string> result;
    if (!dictionary)
    {
        cout << "error";
        exit(0);
    }
    else
    {
        string temp;
        while (dictionary >> temp)
        {
            words.push_back(temp);
        }
    }
    string test = "iwearmyshoes";
    addSpaces(0, test, "", words, result);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}