#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);



int main() {
  string s; cin >> s;
  int n = s.size();
  string ans;
  for (int i=0; i<n;i+=2) ans += s[i];
  cout << ans << endl; 
  return 0;

}
