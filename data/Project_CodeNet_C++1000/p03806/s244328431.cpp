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

int dp[45][450][450];
void solve(){
  int n,ma,mb;
  cin>>n>>ma>>mb;
  vector<int>a(n),b(n),c(n);
  rep(i,n)cin>>a[i]>>b[i]>>c[i];
  rep(i,n+1){
    rep(j,401){
      rep(k,401){
        dp[i][j][k]=1e9;
      }
    }
  }
  dp[0][0][0]=0;
  rep(i,n){
    rep(j,401){
      rep(k,401){
        if(j-a[i]>=0&&k-b[i]>=0)chmin(dp[i+1][j][k],dp[i][j-a[i]][k-b[i]]+c[i]);
        chmin(dp[i+1][j][k],dp[i][j][k]);
      }
    }
  }
  int ans=1e9;
  for(int i=1;i<=40;++i){
    chmin(ans,dp[n][i*ma][i*mb]);
  }
  cout<<(ans!=1e9?ans:-1);
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
