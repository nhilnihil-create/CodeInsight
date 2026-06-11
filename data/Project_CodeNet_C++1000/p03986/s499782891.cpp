#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;cin>>s;
  int sn=0,tn=0;
  for (auto c: s) {
    if (c=='S') {
      sn ++;
    } else {
      if (sn>0) sn--;
      else tn++;
    }
  }
  cout << tn*2;
}
