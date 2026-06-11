#include <bits/stdc++.h>
using namespace std;

int main(){
    string x;
    cin >> x;

    stack<char> word;
    for(int i=0; i<x.length(); i++){
        if(word.empty() == false && word.top() == 'S' && x[i] == 'T') word.pop();
        else word.push(x[i]);
    }
    cout << word.size() << endl;
    return 0;
}