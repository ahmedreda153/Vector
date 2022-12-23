#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<string> col,string prifix,int n){
    if(n==3){
        cout<<prifix<<endl;
        return;
    }
    for (int i = 0; i < col.size(); i++)
    {
        backtracking(col,prifix+" "+to_string(n+1)+"-"+col[i],n+1);
    }
}

int main(){
    vector<string> colors = {"Red","Green","Yellow"};
    int n =0;
    backtracking(colors,"",n);
    return 0; 
}
