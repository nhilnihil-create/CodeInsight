#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string s;
  cin >> s;
  reverse(rng(s));
  for(int i=0; i<s.size(); i++) {
    if(s.substr(i,5)=="maerd") i+=4;
    else if(s.substr(i,5)=="esare") i+=4;
    else if(s.substr(i,6)=="resare") i+=5;
    else if(s.substr(i,7)=="remaerd") i+=6;
    else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}