#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<random>
using namespace std;



//snuke
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define uni(x) x.erase(unique(rng(x)),x.end())
#define df(x) int x = in()
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d", &x); return x; }
inline void priv(vi a) { rep(i, sz(a)) printf("%d%c", a[i], i == sz(a) - 1 ? '\n' : ' '); }
template<typename T>istream& operator>>(istream&i, const vector<T>&v)
{
	rep(j, sz(v))i >> v[j]; return i;
}
template<typename T>string join(const vector<T>&v)
{
	stringstream s; rep(i, sz(v))s << ' ' << v[i]; return s.str().substr(1);
}
template<typename T>ostream& operator<<(ostream&o, const vector<T>&v)
{
	if (sz(v))o << join(v); return o;
}
template<typename T1, typename T2>istream& operator>>(istream&i, const pair<T1, T2>&v)
{
	return i >> v.fi >> v.se;
}
template<typename T1, typename T2>ostream& operator<<(ostream&o, const pair<T1, T2>&v)
{
	return o << v.fi << "," << v.se;
}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

vvi to;
vi used;


class solver{
public:
	int dfs(int v, int c) {
		if (used[v] != -1) {
			return used[v] == c;
		}
		used[v] = c;
		if (sz(to[v]) == 0) return 2;
		int res = 1;
		for (int u : to[v]) {
			if (!dfs(u, c ^ 1)) res = 0;
		}
		return res;
	}
	long long int g[3];
	long long int main(int n,int m,vector<pair<int,int> > lis) {
		to = vvi(n);
		g[0] = g[1] = g[2] = 0;
		rep(i, m) {
			int a, b;
			a = lis[i].first;
			b = lis[i].second;
			to[a].pb(b);
			to[b].pb(a);
		}
		used = vi(n, -1);
		
		rep(i, n) {
			if (used[i] != -1) continue;
			g[dfs(i, 0)]++;
		}
		// cout<<g<<endl;
		ll ans = 0;
		ans += g[0] * g[0];
		ans += g[0] * g[1] * 2;
		ans += g[1] * g[1] * 2;
		// cout<<g<<endl;
		ans += g[2] * n * 2;
		ans -= g[2] * g[2];
		return ans;
	}
};

solver snuke;

#define MAX 200002

int n;
int m;

vector<int> v[MAX];

long long int nf;
long long int bi;
long long int ot;

bool flag[MAX];
bool vis[MAX];

inline bool dfs(int b){
	vis[b] = true;
	bool F = true;
	for (int i = 0; i < v[b].size(); i++){
		int go = v[b][i];
		if (vis[go]){
			if (flag[go] == flag[b])F = false;
		}
		else{
			flag[go] = (flag[b] ^ true);
			if (dfs(go) == false)F=false;
		}
	}
	return F;
}

vector<pair<int, int> > road;

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
		road.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; i++){
		if (vis[i])continue;
		if (v[i].size() == 0){
			nf++;
			continue;
		}
		if (dfs(i)){
			bi++;
		}
		else{
			ot++;
		}
	}
	long long int ans = 0;
	ans += (long long int)(nf)*(long long int)(nf)+(long long int)(nf)*(long long int)(n-nf)*2LL;
	ans += bi*bi * 2LL;
	ans += bi*ot * 2LL;
	ans += ot*ot;
	snuke.main(n, m, road);
	if (bi != snuke.g[1])return 1;
	printf("%lld\n", ans);
	return 0;
}