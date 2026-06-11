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
  ll a, b;
  cin >> a >> b;
  if (a == b) cout << "Draw" << endl;
  else if (a == 1) cout << "Alice" << endl;
  else if (b == 1) cout << "Bob" << endl;
  else if (a > b) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}