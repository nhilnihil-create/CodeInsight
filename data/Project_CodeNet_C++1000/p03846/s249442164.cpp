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
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  map<int,int>mp;
  rep(i,n)mp[a[i]]++;
  ll ans=1;
  bool ng=false;
  if(n%2==0){
    rep(i,n){
      if(i%2==0){
        if(mp[i]>0)ng=true;
      }
      else {
        if(mp[i]!=2)ng=true;
        else ans*=2,ans%=mod;
      }
    }
  }
  else {
    rep(i,n){
      if(i%2==0&&i!=0){
        if(mp[i]!=2)ng=true;
        else ans*=2,ans%=mod;
      }
      else if(i==0){
        if(mp[0]!=1)ng=true;
      }
      else {
        if(mp[i]>0)ng=true;
      }
    }
  }
  if(ng)ans=0;
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
