#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main() {
  ll N, T;
  cin >> N >> T;
  ll out = 0;
  vector<ll> t(N);
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }
  for (int i = 1; i<N; i++){
    ll tmp = 0;
    if (t[i] - t[i - 1] >= T) {
      tmp = T;
      out += tmp;
    } else {
      tmp = t[i] - t[i - 1];
      out += tmp;
    }
  }
  cout << out+T << endl;
  return 0;
}