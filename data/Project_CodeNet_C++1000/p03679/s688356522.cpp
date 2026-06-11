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
  ll x, a, b;
  cin >> x >> a >> b;
  if (a >= b) cout << "delicious" << endl;
  else if (b - a <= x) cout << "safe" << endl;
  else cout << "dangerous" << endl;
}