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
#define rrep(i,a) for(int i=(int)a-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RREP(i,a,b) for(int i=(int)a-1;i>=b;--i)
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
	return abs(n) / gcd(n, m)*abs(m);//gl=xy
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

void solve(){
  int n,k;
  cin>>n>>k;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  ll ans=INF;
  rep(bit,1<<n){
    auto b=a;
    int cnt=0;
    ll sum=0;
    ll maxv=0;
    rep(i,n){
      if(b[i]>maxv){
        ++cnt;
        chmax(maxv,b[i]);
        continue;
      }
      if(bit&(1<<i)){
        sum+=maxv-a[i]+1;
        b[i]+=maxv-a[i]+1;
        //cerr<<b[i]<<"\n";
      }
      if(b[i]>maxv)++cnt;
      chmax(maxv,b[i]);
    }
    //cerr<<cnt<<"\n";
    if(cnt>=k)chmin(ans,sum);
  }
  cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
