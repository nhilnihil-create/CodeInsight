#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
const int INF = 1000000007;
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll fac(ll a) { return a > 1 ? fac(a - 1) * a : 1; }
ll fang(ll a){
  return a > 1 ? fang(a - 1) + a : 1;
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  int a,b,c;
  cin >> a >> b >> c;
  if(b - a == c - b)cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}