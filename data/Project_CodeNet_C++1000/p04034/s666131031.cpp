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
  ll n, m;
  cin >> n >> m;
  vector<bool> red(n, false);
  vl ball(n, 1);
  red[0] = true;
  rep(i, m){
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    ball[x]--;
    ball[y]++;
    if (red[x]){
      red[y] = true;
      if(ball[x]==0){
        red[x] = false;
      }
    }
  }
  ll count = 0;
  for (bool r : red){
    if(r){
      count++;
    }
  }
  print(count);
}