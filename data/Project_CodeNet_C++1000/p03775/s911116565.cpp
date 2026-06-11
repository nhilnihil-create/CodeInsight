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
  ll n;
  cin>>n;
  ll mini = INF;
  for (ll i = 1; i <= sqrt(n);i++){
    if(n%i==0){
      ll a = i, b = n / i;
      ll sza = 0, szb = 0;
      while (a > 0){
        a /= 10;
        sza++;
      }
      while(b>0){
        b /= 10;
        szb++;
      }
      ll m = max(sza, szb);
      chmin(mini, m);
    }
  }
  print(mini);
}