#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  int odd = 0;
  rep (i, n){
    cin >> v[i];
    if (v[i] % 2 == 1) ++odd;
  }
  if (odd % 2 == 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}