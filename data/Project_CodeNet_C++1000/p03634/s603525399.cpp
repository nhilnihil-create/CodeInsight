#include<bits/stdc++.h>
// Begin Header {{{
#define lli long long int
#define rep(i,n) for(lli i=0; i<n; i++)
#define loop(i, j, n) for(lli i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const double PI = acos(-1);
using namespace std;
using Graph = vector<vector<lli>>;
using P = pair<int, int>;
// }}} End Header
typedef struct {
	lli to;
	lli cost;
}edge;
vector<vector<edge>> tree(100010);
vector<lli> dist(100010, 0);
lli K;

void dfs(lli k){
	for(const auto& x : tree[k]){
		if(dist[x.to] > 0 || x.to == K) continue;
		dist[x.to] = dist[k] + x.cost;
		dfs(x.to);
	}
}

int main(){
	lli n, Q;
	cin >> n;
	rep(i,n-1){
		lli a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({b, c});
		tree[b].push_back({a, c});
	}
	cin >> Q >> K;
	dfs(K);
	rep(i,Q){
		lli x, y;
		cin >> x >> y;
		cout << dist[x]+dist[y] << endl;
	}
	return 0;
}