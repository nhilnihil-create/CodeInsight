#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main() {
  int x,a,b;
  cin >> x >> a >> b;
  if (b - a <= 0){
    cout << "delicious\n";
  }
  else if (b - a <= x){
    cout << "safe\n";
  }
  if (b - a > x){
    cout << "dangerous\n";
  }
  return 0;
}