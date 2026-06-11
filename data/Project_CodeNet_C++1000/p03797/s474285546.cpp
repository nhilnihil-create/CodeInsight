#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n, m;
  cin >> n >> m;

  ll x = min(n, m / 2);
  n -= x;
  m -= 2 * x;

  if (m > 1) {
    x += m / 4;
  }

  cout << x << endl;
}