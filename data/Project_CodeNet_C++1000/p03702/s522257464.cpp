#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define mk make_pair
#define pb push_back
#define ll long long 
using namespace std;
const int maxn =2e5+50;
vector<ll> arr;
int n;
ll a, b;
bool is_enough(ll x) {
  vector<ll> h = arr;
  ll cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (h[i] > x * b) {
      cnt += ceil((double)(h[i] - x * b) / (a - b));
    }
  }
  return cnt <= x;
}

int main() {
  cin>>n>>a>>b;
  ll ma = 0;
  for (int i = 0; i < n; ++i) {
   ll h;
    cin>>h;
    arr.pb(h);
    ma = max(h, ma);
  }
 
  ll l = -1, r = ma;
  while (l + 1 < r) {
    ll mid = (l + r) / 2;
    if (is_enough(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout<<r;
  return 0;
}