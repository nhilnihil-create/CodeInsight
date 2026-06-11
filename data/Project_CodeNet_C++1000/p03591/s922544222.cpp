#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define YY puts("Yes")
#define NN puts("No")
const int INF = 1000000007;
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll fac(ll a) { return a > 1 ? fac(a - 1) * a : 1; }
int solve(){
  string s;
  cin >> s;
  if(s.substr(0,4) == "YAKI")YY;
  else NN;
  return 0;
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  // cout << fixed;cout << setprecision(16) << endl; 
  solve();
  return 0;
}