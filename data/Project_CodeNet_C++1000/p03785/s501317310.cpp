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
  ll n,c,k;
  cin >> n >> c >> k;
  vl t(n);
  rep(i,n){
    cin >> t[i];
  }
  sort(all(t));
  ll bus = 0;
  ll passenger = 1;
  ll limit = t[0] + k;
  for (ll i = 1; i < n; i++){
    if(t[i]<=limit&&passenger<c){
      passenger++;
    }
    else{
      bus++;
      passenger = 1;
      limit = t[i] + k;
    }
  }
  bus++;
  print(bus);
}