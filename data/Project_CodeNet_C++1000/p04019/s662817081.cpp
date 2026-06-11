#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    bool n=0,so=0,w=0,e=0;
    for(char c:s){
        if (c=='N') n=1;
        if (c=='S') so=1;
        if (c=='W') w=1;
        if (c=='E') e=1;
        if (n && so && w && e) break;
    }
    if(n && so && w && e){
        cout << "Yes" << endl;
    }
    else if(n && so && !w && !e){
        cout << "Yes" << endl;
    }
    else if(!n && !so && w && e){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}