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
  vector<int>c(26);
  rep(i,h){
    string s;
    cin>>s;
    rep(j,w){
      c[s[j]-'a']++;
    }
  }
  bool ng=false;
  if(h%2==0&&w%2==0){
    rep(i,26){
      c[i]%=4;
      if(c[i])ng=true;
    }
  }
  else if(h%2==1&&w%2==1){
    int cnt=0,one=0;
    rep(i,26){
      c[i]%=4;
      if(c[i]==1)++one;
      else if(c[i]==3)++one,++cnt;
      else if(c[i]==2)++cnt;
    }
    if(cnt>w/2+h/2)ng=true;
    if(one!=1)ng=true;
  }
  else {
    int cnt=0;
    rep(i,26){
      c[i]%=4;
      if(c[i]==2)++cnt;
      else if(c[i])ng=true;
    }
    if(h%2==1){
      if(cnt>w/2)ng=true;
    }
    else {
      if(cnt>h/2)ng=true;
    }
  }
  if(ng)cout<<"No";
  else cout<<"Yes";
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
