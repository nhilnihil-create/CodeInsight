#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF (1<<30);

bool sec_do(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first < b.first;
  } else {
    return a.second > b.second;
  }
}

void sort_bags(vector<vector<int>>& x, const vector<pair<int, int>> w) {
  rep(i, x.size()) x[i].push_back(0);

  int idx = 0;
  x[idx].push_back(w[0].second);
  for (int i = 1; i < w.size(); i++) {
    if (w[i].first != w[i-1].first) idx++;
    x[idx].push_back(w[i].second);
  }

  rep(i, x.size()) {
    for (int j = 1; j < x[i].size(); j++) {
      x[i][j] += x[i][j-1];
    }
  }

}

ll get_ans(const vector<vector<int>> x, ll w1, ll W) {
  ll ans = 0LL;
  rep(i, x[0].size()) {
    rep(j, x[1].size()) {
      rep(k, x[2].size()) {
        rep(l, x[3].size()) {
          ll weight = i * w1 + j * (w1+1) + k * (w1+2) + l * (w1+3);
          if (weight > W) continue;
          ans = max(ans, (ll)x[0][i]+x[1][j]+x[2][k]+x[3][l]);
        }
      }
    }
  }

  return ans;
}

int main() {
  int N; ll W; cin >> N >> W;
  vector<pair<int, int>> w(N);
  rep(i, N) cin >> w[i].first >> w[i].second;

  sort(all(w), sec_do);

  vector<vector<int>> x(4);
  sort_bags(x, w);


  ll w1 = w[0].first;
  ll ans = get_ans(x, w1, W);

  cout << ans << endl;

  return 0;
}

