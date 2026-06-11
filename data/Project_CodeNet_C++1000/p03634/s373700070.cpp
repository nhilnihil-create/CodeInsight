#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

vector<P> to[100010];
ll cost[100010];

int n;
void dfs(int from,int p,ll dist) {
	cost[p]=dist;
	for(auto x: to[p]){
		if(x.first == from) continue;
		dfs(p, x.first, dist + x.second);
	}
	return ;
}
int main()
{
	cin >> n;
	rep(i,n-1){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		to[a].push_back({b,c});
		to[b].push_back({a,c});
	}
	int q, k;
	cin >> q >> k;
	--k;
	dfs(-1,k,0);
	vector<ll> ans(q);
	rep(i,q){
		int x, y;
		cin >> x >> y;
		--x, --y;
		ans[i] = cost[x] + cost[y];
	}
	rep(i,q) cout << ans[i] << endl;
}
