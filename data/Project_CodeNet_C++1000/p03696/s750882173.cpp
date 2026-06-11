#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int tmp=0;
    int MIN=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(' && tmp>=0)tmp++;
        else if(s[i]=='(' && tmp<0){
            MIN-=tmp;
            tmp=1;
        }
        else tmp--;
    }
    if(tmp<0)MIN-=tmp;
    for(int i=0;i<MIN;i++)cout << "(";
    cout << s;
    for(int i=0;i<tmp;i++)cout << ")";
}