#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n, k;
  cin >> n >> k;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }


  ll res = 0;

  vector<ll> s(n + 1, 0);
  for (int i = 0; i < n; i++){
    s[i + 1] = s[i] + (a[i] > 0 ? a[i] : 0);
  }

  ll u = 0;
  for (int i = 0; i < k; i++){
    u += a[i];
  }

  ll v = s[0], w = s[n] - s[k];
  res = max(res, max(v + w, v + w + u));
  for (int i = 1; i < n - k + 1; i++){
    u += a[i + k - 1] - a[i-1];
    ll v = s[i];
    ll w = s[n] - s[i + k];
    res = max(res, max(v + w + u, v + w));
  }

  cout << res << endl;

  return 0;
}
