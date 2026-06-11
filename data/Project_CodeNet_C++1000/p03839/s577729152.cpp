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

void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    vector<ll>sum(n+1),pos(n+1);
    rep(i,n)sum[i+1]=sum[i]+a[i];
    rep(i,n){
        if(a[i]>=0)pos[i+1]=pos[i]+a[i];
        else pos[i+1]=pos[i];
    }
    ll ans=0;
    rep(i,n-k+1){
        ll cul=max(0LL,sum[i+k]-sum[i]);
        cul+=pos[n]-pos[i+k];
        cul+=pos[i];
        chmax(ans,cul);
    }
    cout<<ans;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
