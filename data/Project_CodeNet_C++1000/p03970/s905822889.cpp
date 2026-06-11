/*
      author : nishi5451
      created: 12.08.2020 00:26:56
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    string code = "CODEFESTIVAL2016";
    int ans=0;
    rep(i,16) if(s[i] != code[i]) ans++;
    cout << ans << endl; 
    return 0;
}