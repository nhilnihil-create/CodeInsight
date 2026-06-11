#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
using namespace std;
#define _GLIBCXX_DEBUG
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vit vector<lint>::iterator
#define all(x) (x).begin(),(x).end()
#define rep(x) for(int i = 0;i < (x);i++)
#define repj(x) for(int j = 0;j < (x);j++)
#define REP(i,x) for(int (i) = 0;(i) < (x);(i)++)
#define rrep(x) for(int i = (x);i >= 0;i--)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define mod 1000000007
#define graph_set(n) struct edge{int to,int cost;} vector<edge> G((n))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define range(x,y) ((x) >= 0 && (x) < h && (y) >= 0 && (y) < w)
#define pyes cout << "Yes" << endl
#define pno cout << "No" << endl
typedef vector<long long> vi;
typedef vector<pair<long long, long long>> vp;
typedef vector<vector<long long>> vvi;
typedef pair<long long, long long> pi;
typedef long long lint;
typedef long long ll;
lint qp(int a, ll b) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
lint qp(int a, ll b, int mo) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
lint gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
long long INF = 1e19;
#define MAX_N 200010
class UnionFind {
public:
	//UnionFind
	int par[MAX_N];
	int ufrank[MAX_N];
	int ufsize[MAX_N];
	UnionFind(int ufsize_of_tree) {
		for (int i = 0; i < ufsize_of_tree; i++)
		{
			par[i] = i;
			ufrank[i] = 0;
			ufsize[i] = 1;
		}
	}
	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (ufrank[x] < ufrank[y]) {
			par[x] = y;
			int sx = ufsize[x], sy = ufsize[y];
			ufsize[x] = ufsize[y] = sx + sy;
		}
		else {
			par[y] = x;
			if (ufrank[x] == ufrank[y]) ufrank[x]++;
			int sx = ufsize[x], sy = ufsize[y];
			ufsize[x] = ufsize[y] = sx + sy;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};
//////////////////////////////////////////////////////////////////////
ll n, m;
ll x[100010], y[100010];
int main() {
	cin >> n >> m;
	rep(n)cin >> x[i];
	rep(m)cin >> y[i];
	
	ll X=0, Y=0;
	rep(n-1) {
		ll sx;
		sx = (x[i + 1] - x[i])*(i+1) %mod;
		sx *= (n - i - 1); sx %= mod;
		X += sx; X %= mod;
	}
	rep(m - 1) {
	    ll sy;
		sy = (y[i + 1] - y[i])*(i+1) %mod;
		sy *= (m - i - 1); sy %= mod;
		Y += sy; Y %= mod;
	}
	cout << X * Y % mod << endl;

	return 0;
}