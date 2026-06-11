#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  ll Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  ll ans = N/2*min(8*Q, min(4*H, min(2*S, D))) + N%2*min(4*Q, min(2*H, S));
  cout << ans << endl;
}