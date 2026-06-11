// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)


int main() {
  ll n, k; cin >> n >> k;
  vector<ll> A(n);
  loop(i,0,n) cin >> A[i];
  ll ans = 0;
  loop(i,0,n-1) {
    if (A[i] + A[i+1] <= k) continue;
    {
      ll d = min(A[i+1], A[i]+A[i+1]-k);
      A[i+1] -= d;
      ans += d;
    }
    if (A[i] + A[i+1] <= k) continue;
    {
      ll d = min(A[i], A[i]+A[i+1]-k);
      A[i] -= d;
      ans += d;
    }
  }
  cout << ans << endl;
  return 0;
}
