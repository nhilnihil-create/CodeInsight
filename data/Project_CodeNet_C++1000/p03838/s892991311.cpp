#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  ll x,y;
  cin >> x >> y;
  ll a = (-1) * x, b = (-1) * y;
  ll ans = INF;
  if(y-x>=0){
    chmin(ans, y - x);
  }
  if(y-a>=0){
    chmin(ans, y - a + 1);
  }
  if(b-x>=0){
    chmin(ans, b - x + 1);
  }
  if(b-a>=0){
    chmin(ans, b - a + 2);
  }
  print(ans);
}