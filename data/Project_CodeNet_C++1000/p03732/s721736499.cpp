#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807/2;
const int MOD = 1000000007;
const int N_MAX = 100;
const int W_MAX = 300;

int main() {
  ll N, W; cin >> N >> W;
  ll w[N], v[N]; rep(i,N) cin >> w[i] >> v[i];;

  vector<vector<ll>> x(4, vector<ll>());
  ll dw = w[0];
  rep(i, N) x[w[i]-dw].push_back(v[i]);
  rep(i, 4) {
    sort(x[i].begin(), x[i].end(), greater<int>());
    for(int j=1; j<x[i].size(); j++) x[i][j] += x[i][j-1];
    x[i].insert(x[i].begin(), 0);
  }


  ll result = 0;
  rep(w0, x[0].size()) rep(w1, x[1].size())
  rep(w2, x[2].size()) rep(w3, x[3].size()) {
    ll w_sum = dw*w0 + (dw+1)*w1 + (dw+2)*w2 + (dw+3)*w3;
    ll v_sum = x[0][w0] + x[1][w1] + x[2][w2] + x[3][w3];
    if (w_sum <= W) result = max(result, v_sum);
  }
  cout << result << endl;
  return 0;
}