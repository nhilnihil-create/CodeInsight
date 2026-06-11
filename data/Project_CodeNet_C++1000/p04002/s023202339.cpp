#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;


int main() {
  int H, W, N;
  cin >> H >> W >> N;
  set< pair< int, int > > mp;
  for(int i = 0; i < N; i++) {
    int y, x;
    cin >> y >> x;
    --y, --x;
    mp.emplace(y, x);
  }
  set< pair< int, int > > added;
  vector< int64 > sum(10);
  for(auto &p : mp) {
    for(int i = -2; i <= 0; i++) {
      for(int j = -2; j <= 0; j++) {
        int y = p.first + i, x = p.second + j;
        if(y < 0 || x < 0) continue;
        if(y + 2 >= H || x + 2 >= W) continue;
        if(added.count({y, x})) continue;
        added.emplace(y, x);
        int cost = 0;
        for(int k = 0; k < 3; k++) {
          for(int l = 0; l < 3; l++) {
            cost += mp.count({y + k, x + l});
          }
        }

        sum[cost]++;
      }
    }
  }
  int64 all = 1LL * (H - 2) * (W - 2);
  for(int i = 1; i < 10; i++) all -= sum[i];
  sum[0] = all;
  for(auto &p : sum) cout << p << endl;
}