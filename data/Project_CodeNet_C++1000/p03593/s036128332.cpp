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
  int h,w;
  cin>>h>>w;
  vector<string>a(h);
  rep(i,h)cin>>a[i];
  bool ok=false;
  vector<int>c(26);
  rep(i,h){
    rep(j,w){
      c[a[i][j]-'a']++;
    }
  }
  int sum=0;
  rep(i,26){
    sum+=c[i]/4;
    c[i]%=4;
  }
  if(h%2==1&&w%2==1){
    int two=(h+w-2)/2;
    int one=1;
    rep(i,26){
      if(c[i]==2)two-=c[i]/2;
      else if(c[i]==1)one-=c[i];
    }
    if(two>=0&&one==0)ok=true;
  }
  else if(h%2==1){
    int two=w/2;
    bool ng=false;
    rep(i,26){
      if(c[i]==2)two-=c[i]/2;
      if(c[i]%2)ng=true;
    }
    if(!ng&&two>=0)ok=true;
  }
  else if(w%2==1){
    int two=h/2;
    bool ng=false;
    rep(i,26){
      if(c[i]==2)two-=c[i]/2;
      if(c[i]%2)ng=true;
    }
    if(!ng&&two>=0)ok=true;
  }
  else {
    bool ng=false;
    rep(i,26){
      if(c[i]!=0)ng=true;
    }
    if(!ng)ok=true;
  }
  if(ok)cout<<"Yes";
  else cout<<"No";
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}