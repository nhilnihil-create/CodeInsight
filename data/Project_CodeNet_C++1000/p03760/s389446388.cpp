#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string o,e;
  cin>>o>>e;
  rep(i,e.size()){
    cout<<o[i];
    cout<<e[i];
  }
  if(o.size()!=e.size()){
    cout<<o.back();
  }
}