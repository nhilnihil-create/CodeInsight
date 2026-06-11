#include<bits/stdc++.h>
using namespace std;

int main(){
    string w;
    cin >> w;
    set<char> se;
    for(char c : w){
        if(se.find(c) == se.end()) se.insert(c);
        else se.erase(c);
    }
    if(se.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
}