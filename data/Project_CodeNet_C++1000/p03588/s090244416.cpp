#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll>> AB(N);
  for (int i=0; i<N; i++) cin >> AB[i].first >> AB[i].second;
  sort(AB.begin(), AB.end());
  ll ans = AB[N-1].first+AB[N-1].second;
  cout << ans << endl;
  return 0;
}