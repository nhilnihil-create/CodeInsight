#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    string s;
    cin >> s;
    set<char> ss;
    for(int i=0; i<(int)s.length(); ++i){
        ss.insert(s[i]);
    }
    if(ss.size()==s.length())
        cout << "yes";
    else
        cout << "no";
    return 0;
}