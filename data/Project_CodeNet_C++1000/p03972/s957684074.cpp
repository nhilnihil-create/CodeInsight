#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int H,W;
  cin >> H >> W;
  ll p[H];
  ll q[W];
  ll ans = 0;
  for (int i = 0; i < H; i++) {
    cin >> p[i];
    ans += p[i];
  }
  for (int j = 0; j < W; j++) {
    cin >> q[j];
    ans += q[j];
  }

  sort(q,q+W);

  ll sum[W+1];
  sum[0] = 0;
  for (int i = 0; i < W; i++) {
    sum[i+1] = sum[i] + q[i];
  }
  
  for (int i = 0; i < H; i++) {
    int s = lower_bound(q,q+W,p[i]) - q;
    ans += sum[s];
    ans += p[i] * ((ll)W - s);
  }

  cout << ans << endl;
  return 0;
}