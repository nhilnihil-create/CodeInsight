#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  vector<char> s; int i = 0;
  rep(i,ty-sy) s.push_back('U');
  rep(i,tx-sx) s.push_back('R');
  rep(i,ty-sy) s.push_back('D');
  rep(i,tx-sx) s.push_back('L');
  s.push_back('L');
  rep(i,ty-sy+1) s.push_back('U');
  rep(i,tx-sx+1) s.push_back('R');
  s.push_back('D');
  s.push_back('R');
  rep(i,ty-sy+1) s.push_back('D');
  rep(i,tx-sx+1) s.push_back('L');
  s.push_back('U');
  rep(i,s.size()) cout << s.at(i);
  cout   << endl;
}