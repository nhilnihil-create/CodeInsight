#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;

string ans = "";
void binding(int a, char b) {
  rep(i,a) ans += b;
}
int main() {
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  int x = tx-sx, y = ty-sy;
  binding(y,'U');
  binding(x,'R');
  binding(y,'D'); 
  binding(x,'L');
  ans += 'L';
  binding(y+1,'U');
  binding(x+1,'R');
  ans += 'D'; ans += 'R';
  binding(y+1,'D');
  binding(x+1,'L');
  ans += 'U';

  cout << ans << endl;

  return 0;
}