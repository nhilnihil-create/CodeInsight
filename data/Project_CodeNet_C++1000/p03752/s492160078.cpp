// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void recursive_comb(int *indexes, int s, int rest, function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main() {
  int k,n;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 1e16;
  foreach_comb(n, k, [&](int *indexes) {
    // indexes[0] より左に高い建物がないことを確認する
    // 高い建物があるなら、その建物を選んだときの方がコストは低い
    for(int i=indexes[0]-1;i>=0;i--) {
      if(a[indexes[0]] < a[i]) {
        return;
      }
    }

    int cur = 0;
    ll val = 0;
    ll h = a[indexes[cur]];
    while(cur < k - 1) {
      // indexes[cur]とindexes[cur+1]の間にhよりも高いビルがあったら
      // hをその高さに合わせる
      for(int i=indexes[cur]+1;i<indexes[cur+1];i++) {
        if(h < a[i]) {
          h = a[i];
        }
      }
      ll h_n = a[indexes[cur+1]];
      if(h < h_n) {
        h = h_n;
        cur++;
        continue;
      }
      h = h+1;
      val += h - h_n;
      cur++;
    }
    // printf("%d %d %d → %d\n", indexes[0], indexes[1], indexes[2], val);
    ans = min(ans, val);
  });

  cout << ans << endl;
  return 0;
}
