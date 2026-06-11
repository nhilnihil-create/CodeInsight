#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);

void solve() {
  string a,b,c; cin >> a >> b >> c;
  int a_n = a.size()-1;
  int b_n = b.size()-1;
  int c_n = c.size()-1;
  if (a[a_n] == b[0] && b[b_n] == c[0]) {
    cout << "YES" << endl;
  } 
  else {
    cout << "NO" << endl;
  }
}

int main() {
  solve();
  return 0;
}

