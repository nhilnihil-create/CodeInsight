#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}

#define N 310
ll a[N][N], n, mn[N][N];

struct UF {
	int par[N],rank[N];
	
	void init(int n){
		for(int i = 0; i < n; i++){
			par[i] = i;
			rank[i] = 0;
		}
	}
	
	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}
	
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = par[x];
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
	
	bool same(int x, int y){
		return find(x) == find(y);
	}
};
int main(){
	cin>>n;
	rep(i, n) rep(j, n) cin>>a[i][j];
	bool ok = true;
	rep(i, n) rep(j, n) mn[i][j] = 1;
	rep(i, n) rep(j, n) rep(k, n){
		if(a[i][j]>a[i][k]+a[k][j]) ok = false;
		if(a[i][j]==a[i][k]+a[k][j] && i!=k && j!=k) mn[i][j] = 0;
	}
	if(!ok){
		cout<<-1<<endl;
		return 0;
	}
	ll res = 0;
	rep(i, n) rep(j, n) res += mn[i][j]*a[i][j];
	cout<<res/2<<endl;
	/*
	UF uf;
	uf.init(n);
	vector<PP> v;
	rep(i, n) rep(j, i) v.push_back(PP(a[i][j], P(i, j)));
	sort(all(v));
	ll res = 0;
	rep(i, v.size()){
		int x = v[i].snd.fst, y = v[i].snd.snd;
		if(!uf.same(x, y)){
			uf.unite(x, y);
			res += v[i].fst;
		}
	}
	cout<<res<<endl;
	*/
	return 0;
}
