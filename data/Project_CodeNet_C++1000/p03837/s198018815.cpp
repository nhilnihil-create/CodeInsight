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

const int INFTY=(numeric_limits<int>::max())/2;
vector<vector<int>>d;//d[u][v]は辺uvのコスト、ただし存在しないときINFTY,d[i][i]=0

void warshall_floyd(int V){//Vは頂点数
	for(int k=0;k<V;++k){//経由する頂点
		for(int i=0;i<V;++i){//始点となる頂点
			for(int j=0;j<V;++j)//目的地の頂点
      d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
}

void solve(){
  int n,m;
  cin>>n>>m;
  d.resize(n,vector<int>(n,INFTY));
  rep(i,n)d[i][i]=0;
  vector<int>a(m),b(m),c(m);
  rep(i,m){
    cin>>a[i]>>b[i]>>c[i];
    a[i]--;b[i]--;
    d[a[i]][b[i]]=c[i];
    d[b[i]][a[i]]=c[i];
  }
  warshall_floyd(n);
  vector<bool>used(m);
  //rep(i,n)rep(j,n)cout<<d[i][j]<<endl;
  rep(i,n){
    rep(j,n){
      rep(k,m){
        if(d[i][j]==d[i][a[k]]+d[b[k]][j]+c[k])used[k]=true;
      }
    }
  }
  //rep(i,m)cout<<used[i]<<"\n";
  int cnt=0;
  rep(i,m)if(!used[i])++cnt;
  cout<<cnt;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
