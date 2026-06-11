#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s;
    int l=s.length();
    bool ans=true;
    int i=0;
    while(1){
        if(s.at(l-1)=='r' && s.at(l-3)=='m'){
            t+="remaerd";
            l-=7;
        }
        else if(s.at(l-1)=='m'){
            t+="maerd";
            l-=5;
        }
        else if(s.at(l-1)=='r' && s.at(l-3)=='s'){
            t+="resare";
            l-=6;
        }
        else if(s.at(l-1)=='e'){
            t+="esare";
            l-=5;
        }
        i++;
        if(l==0 || i>100000) break;
    }
    reverse(t.begin(),t.end());
    if(t==s) cout << "YES" << endl;
    else cout << "NO" << endl;
}