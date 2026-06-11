#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int H, W, N;
int a[100010], b[100010];
map<pii, int> mp;
int cnt[10];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> H >> W >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    for (int y = 0; y < 3 && a[i]+y < H; y++) {
      for (int x = 0; x < 3 && b[i]+x < W; x++) {
        mp[pii(a[i]+y, b[i]+x)]++;
      }
    }
  }
  for (auto p : mp) {
    if (p.first.first >= 2 && p.first.second >= 2) {
      cnt[p.second]++;
    }
  }
  int sum = accumulate(cnt+1, cnt+10, 0);
  cout << (ll)(H-2)*(W-2) - sum << endl;
  for (int i = 1; i < 10; i++) {
    cout << cnt[i] << endl;
  }

  return 0;
}