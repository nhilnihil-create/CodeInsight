#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n)repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
typedef pair<int,int> P;
typedef pair<int, P> PP;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define fi first
#define se second
const int inf = 1e9+7;
const int INF = 1e18+7;
int mod = 1e9+7;

const int MAX = 300000;
map<P,int> mp;
int par[2][MAX], size[2][MAX], sum[2][MAX];

void init(){
	rep(i,MAX)rep(j,2)par[j][i] = i;
	rep(i,MAX)rep(j,2)sum[j][i] = 1;
}

int find(int t, int x){
	if(par[t][x] == x)return x;
	return par[t][x] = find(t, par[t][x]);
}

void unite(int t, int x, int y){
	x = find(t, x);
	y = find(t, y);
	if(size[t][x] < size[t][y]){
		par[t][x] = y;
		sum[t][y]++;
	}else{
		par[t][y] = x;
		if(size[t][x] == size[t][y])size[t][y]++;
		sum[t][x]++;
	}
}

bool same(int t, int x, int y){
	return find(t, x) == find(t, y);
}

vector<int> ans;
signed main(){
	init();
	int n, m1, m2;
	scanf("%lld%lld%lld", &n, &m1, &m2);
	
	rep(i,m1){
		int x, y;
		scanf("%lld%lld",&x, &y);
		unite(0, x-1, y-1);
	}
	rep(i,m2){
		int x, y;
		scanf("%lld%lld", &x, &y);
		unite(1, x-1, y-1);
	}
	
	rep(i,n){
		int x = find(0, i), y = find(1, i);
		mp[P(x, y)]++;
	}
	rep(i,n){
		int x = find(0, i), y = find(1, i);
		ans.push_back(mp[P(x, y)]);
	}
	
	rep(i,ans.size())printf("%lld%c", ans[i], i == ans.size()-1 ? '\n' : ' ');
	return 0;
}
