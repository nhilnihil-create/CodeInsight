#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int64_t n,k; cin >> n >> k;
  int64_t ans = k*pow(k-1,n-1);
  printf("%ld\n", ans);
}