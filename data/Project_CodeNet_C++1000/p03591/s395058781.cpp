/*
      author : nishi5451
      created: 12.08.2020 00:33:35
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    string init = s.substr(0,4);
    if(init=="YAKI") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}