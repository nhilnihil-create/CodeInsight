#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
//const int MOD = 1000000007;
const ll MOD=998244353;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(){
  string s,t;
  cin>>s;
  t="YAKI";
  if(s.substr(0,4)==t)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}