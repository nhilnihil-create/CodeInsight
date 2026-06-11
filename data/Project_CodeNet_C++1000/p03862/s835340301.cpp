#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;

int main() {
  int N;
  ll x;
  cin >> N >> x;
  vector<ll> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
  ll res = 0;
  if (a[0]>x) {
    res += a[0]-x;
    a[0] = x;
  }
  for (int i=0; i<N-1; i++) {
    if (a[i]+a[i+1]>x) {
      res += a[i]+a[i+1]-x;
      a[i+1] = x-a[i];
    }
  }
  cout << res << endl;
  return 0;
}