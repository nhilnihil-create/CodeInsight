#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)


int main() {
  ll sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;

  rep(i,ty-sy) cout << 'U';
  rep(i,tx-sx) cout << 'R';
  rep(i,ty-sy) cout << 'D';
  rep(i,tx-sx+1) cout << 'L';
  rep(i,ty-sy+1) cout << 'U';
  rep(i,tx-sx+1) cout << 'R';
  cout << 'D';
  cout << 'R';
  rep(i,ty-sy+1) cout << 'D';
  rep(i,tx-sx+1) cout << 'L';
  cout << 'U';
  cout << endl;

  return 0;
}