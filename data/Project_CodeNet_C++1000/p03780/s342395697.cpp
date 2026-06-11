#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#include<random>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

ll gcd(ll n, ll m) {
	ll tmp;
	while (m!=0) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m) {
	return abs(n * m) / gcd(n, m);//gl=xy
}
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;

//ここから

void solve(){
  ll n,K;
  cin>>n>>K;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  sort(a.begin(),a.end());
  int l=-1,r=n;
  while(r-l>1){
    int i=(l+r)/2;
    vector<vector<bool>>dp(n+1,vector<bool>(5005));
    dp[0][0]=true;
    rep(k,n){
      rep(j,5001){
        if(k!=i&&j-a[k]>=0)dp[k+1][j]=dp[k][j]|dp[k][j-a[k]];
        else dp[k+1][j]=dp[k][j];
      }
    }
    bool ng=false;
    rep(j,5001){
      if(dp[n][j]==true&&j<K&&j+a[i]>=K)ng=true;//不必要ではない
    }
    if(ng)r=i;
    else l=i;
  }


  cout<<r;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
