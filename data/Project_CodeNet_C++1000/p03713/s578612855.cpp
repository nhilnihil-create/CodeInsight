#include <bits/stdc++.h>
using namespace std;

#define sswap(x, y) { x+=y; y=x-y; x-=y; }
#define LSOne(S) ((S) & (-S))

#define EPS 1e-6
#define MOD 1000000007

#define fi first
#define se second
#define pb push_back
#define ende '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mset(x, y) memset(&x, (y), sizeof(x))

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll H, W;
  cin >> H >> W;
  ll best = 1012345;
  ll start = 0;
  ll ending = 0;
  for (ll h = start; h < H+ending; h++) {
    //AAAAAAAAA
    //BBBBBBBBB
    //CCCCCCCCC
    ll A, B, C;
    A = W*h;
    B = W*((H-h)/2);
    C = W*((H-h+1)/2);
    ll maybe = max({A, B, C})-min({A, B, C});
    best = min(best, maybe);
    //AAAAAAA
    //BBBBCCC
    //BBBBCCC
    B = (H-h)*(W/2);
    C = (H-h)*((W+1)/2);
    maybe = max({A, B, C})-min({A, B, C});
    best = min(best, maybe);
  }
  for (ll w = start; w < W+ending; w++) {
    //ABC
    //ABC
    //ABC
    ll A, B, C;
    A = H*w;
    B = H*((W-w)/2);
    C = H*((W-w+1)/2);
    ll maybe = max({A, B, C})-min({A, B, C});
    best = min(best, maybe);
    //ABB
    //ABB
    //ACC
    B = (H/2)*(W-w);
    C = ((H+1)/2)*(W-w);
    maybe = max({A, B, C})-min({A, B, C});
    best = min(best, maybe);
  }
  cout << best << ende;
  return 0;
}
