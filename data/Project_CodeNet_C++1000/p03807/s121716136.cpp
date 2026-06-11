#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n;
  cin >> n;
  vll a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    if (a[i] % 2 == 1) cnt++;
  }
  if (cnt % 2) NO();
  else YES();
}