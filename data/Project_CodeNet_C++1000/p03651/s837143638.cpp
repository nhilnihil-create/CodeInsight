#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int M = 1;
  rep(i,n) {
    cin >> a[i];
    if(M<a[i]) M = a[i];
  }
  int g = 0;
  rep(i,n) g = gcd(g,a[i]);
  cout << (M>=k&&k%g==0? "POSSIBLE" : "IMPOSSIBLE") << endl;
  return 0;
}