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
  int n,m;
  cin>>n>>m;
  vector<int>x(n);
  map<int,int>mp,mp2;
  vector<int>v(1e5+10);
  rep(i,n)cin>>x[i],mp[x[i]%m]++,v[x[i]]++;
  rep(i,1e5+5){
    mp2[i%m]+=v[i]/2;
  }
  int ans=0;
  for(auto x: mp){
    int minv=min(x.second,mp[(m-x.first)%m]);
    if((x.first==0)||(2*x.first==m))continue;
    ans+=minv;
    mp[x.first]-=minv;
    mp[(m-x.first)%m]-=minv;
    if(mp[x.first]>=2)ans+=min(mp[x.first]/2,mp2[x.first]);
    //cerr<<x.first<<" "<<ans<<endl;
  }
  ans+=mp[0]/2;
  if(m%2==0){
    ans+=mp[m/2]/2;
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
