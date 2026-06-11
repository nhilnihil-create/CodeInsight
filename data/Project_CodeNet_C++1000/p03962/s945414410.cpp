#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);
// int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
// int a[12][12];



void solve() {
  int x,y,z;
  cin >> x >> y >> z;
  if (x == y && y ==z && x == z) cout << 1 << endl;
  else if ((x == y && y!=z) || (x!=y && y==z) || (x==z && z!=y)) cout << 2 << endl;
  else cout << 3 << endl;
  
}


int main() {
  solve();
  return 0;
}