#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n, tt;
  cin >> n >> tt;

  vll t(n);
  for (ll i = 0; i < n; i++) cin >> t[i];

  ll ans = tt * n;
  for (ll i = 0; i < n - 1; i++) {
    if (t[i + 1] - t[i] < tt) ans -= tt - (t[i + 1] - t[i]);
  }

  cout << ans << endl;
}