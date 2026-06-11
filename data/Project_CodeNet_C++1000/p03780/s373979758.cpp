#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using vb = vector<bool>;
using boolGraph = vector<vb>;
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int N, K; cin >> N >> K;
  vi arr;
  rep(i,N) {
    int x; cin >> x;
    if (x < K) arr.push_back(x);
  }

  sort(rall(arr));

  boolGraph dp(arr.size()+1, vb(K, false));
  rep(i,dp.size()) dp[i][0] = true;
  rep(i,arr.size()) {
    rep(j,K-arr[i]) {
      dp[i+1][j+arr[i]] = dp[i][j] || dp[i][j+arr[i]];
    }
  }

  reverse(all(arr));

  boolGraph dp2(arr.size()+1, vb(K, false));
  rep(i,dp2.size()) dp2[i][0] = true;
  rep(i,arr.size()) {
    rep(j,K-arr[i]) {
      dp2[i+1][j+arr[i]] = dp2[i][j] || dp2[i][j+arr[i]];
    }
  }

  int ans = arr.size();

  rep(i,arr.size()) {
    vi tmp(K+1);
    rep(j,K) tmp[j+1] = tmp[j] + (dp2[i][j] ? 1 : 0);

    int h = arr.size()-1 - i;

    rep(j,K) {
      if (!dp[h][j]) continue;

      if (j < K-arr[i] && tmp[K-j] == tmp[K-arr[i]-j]) continue;
      
      --ans;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
