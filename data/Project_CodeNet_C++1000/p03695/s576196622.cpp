#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector<vi>;
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
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll dp[9];
int main(){
  ll n;
  cin >> n;
  rep(i,n){
    ll a;
    cin >> a;
    if(a>=3200){
      dp[8]++;
    }
    else{
      dp[a / 400]++;
    }
  }
  ll count=0;
  rep(i, 8){
    if(dp[i]>0)count++;
  }
  ll m = count;
  m += dp[8];
  if(count==0)count++;
  cout << count << " ";
  if(dp[m]>8){
    print(8);
  }
  else{
    print(m);
  }
}
