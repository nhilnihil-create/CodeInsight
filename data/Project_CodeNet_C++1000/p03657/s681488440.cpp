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
  ll a, b;
  cin >> a >> b;
  if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}