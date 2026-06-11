#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b=0,c=0;cin >> a;
    string s;cin >> s;
    for (int i=0;i<a;i++){
        if (s[i]=='I'){
            c++;
        }
        else if (s[i]=='D'){
            c--;
        }
        if (b<c){
            b=c;
        }
    }
    cout << b;
}