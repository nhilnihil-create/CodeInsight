#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;

int main() {
  ll N, P;
  cin >> N >> P;
  vector<ll> A(N);
  for (ll i=0; i<N; i++) cin >> A[i];
  // A_iがすべて偶数かどうか
  bool even = true;
  for (ll i=0; i<N; i++) {
    if (A[i]%2!=0) {
      even = false;
      break;
    }
  }
  if (even) {
    if (P==0) cout << (ll)pow(2, N) << endl;
    else cout << 0 << endl;
  }
  else cout << (ll)pow(2, N-1) << endl;
}