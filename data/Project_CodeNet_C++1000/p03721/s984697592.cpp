#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<pair<ll, ll>> ab(N);
  for (ll i=0; i<N; i++) cin >> ab[i].first >> ab[i].second;
  sort(ab.begin(), ab.end());
  ll sum = 0; // 今までの登場回数の合計
  for (ll i=0; i<N; i++) {
    sum += ab[i].second;
    if (K<=sum) {
      cout << ab[i].first << endl;
      break;
    }
  }
}