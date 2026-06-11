#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef pair<P, int> Pi;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
const int INF = 1e18+7;

vector<int> G[200000];
int used[200000], d[200000], par[200000];
int n, k, ans = 0;
int dfs(int v){
	if(used[v])return 0;
	used[v] = 1;
	int mx = 0;
	rep(i,G[v].size()){
		chmax(mx, dfs(G[v][i])+1);
	}
	//if(v == 3)printf("*%lld*\n", mx);
	//if(par[v] == -1 and v != 0)printf("*%lld*\n", v);
	if(v == 0)return 0;
	if(par[v] == -1)ans++;
	else if(mx == k-1){
		if(par[v] == 0)return 0;
		//if(v == 3)printf("*%lld*\n", v);
		ans++;d[v] = -1;mx = -1;
	}
	return mx;
}

signed main(){
	fill(par, par+200000, -1);
	scanf("%lld%lld", &n, &k);
	rep(i,n){
		int x;
		scanf("%lld", &x);x--;
		if(i == 0){
			if(x != 0)ans++;
			continue;
		}
		par[i] = x;
		G[x].pb(i);
	}
	
	rep(i,n){
		if(used[i] == 0)dfs(i);
	}
	printf("%lld\n", ans);
	return 0;
}





