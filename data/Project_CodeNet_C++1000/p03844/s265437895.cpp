/*
      author : nishi5451
      created: 11.08.2020 00:07:43
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    ll a,b;
    string op;
    cin >> a >> op >> b;
    if(op == "+"){
        cout << a+b << endl;
    }
    else if(op=="-"){
        cout << a-b << endl;
    }
    return 0;
}