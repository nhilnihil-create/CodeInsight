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
  vector<vll> v(n, vll(2));
  for (ll i = 0; i < n; i++) {
    cin >> v[i][0] >> v[i][1];
  }
  sort(all(v));
  cout << v[n - 1][0] + v[n - 1][1] << endl;
}