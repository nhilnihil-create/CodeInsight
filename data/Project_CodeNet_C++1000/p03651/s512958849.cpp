#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;
ll gcd(ll a, ll b){
  if (a < b)
    return gcd(b, a);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main(void){
  ll n, k;
  cin >> n >> k;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  ll g = a[0];
  for (int i = 0; i < n - 1; i++){
    g = gcd(g, a[i + 1]);
  }
  int ok = 0;
  for (int i = 0; i < n; i++){
    if (a[i] - k >= 0 && (a[i] - k) % g == 0)
      ok = 1;
  }
  if (ok)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
    

  return 0;
}
