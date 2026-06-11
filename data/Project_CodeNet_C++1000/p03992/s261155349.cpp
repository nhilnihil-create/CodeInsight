#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける

int main() {
  string str;
  cin >> str;
  rep(i,4) cout << str.at(i);
  cout << " ";
  rep(i,8) cout << str.at(i+4);
  cout << endl;
  return 0;
}