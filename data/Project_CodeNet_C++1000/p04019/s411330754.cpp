#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    bool n=0,s=0,w=0,e=0;

    for(int i=0; i<str.size(); i++){
        if(str.at(i)=='N') n=true;
        if(str.at(i)=='S') s=true;
        if(str.at(i)=='E') e=true;
        if(str.at(i)=='W') w=true;
    }
    if(s==n && e==w) cout << "Yes" << endl;
    else cout << "No" << endl;
}