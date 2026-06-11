#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  rep(i,s.size()){
    if(i%2==0) cout << s[i];
  }
}