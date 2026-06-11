#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MA = 100099;
int vis[MA], col[MA];
bool isBi;
int ccSize;
vi G[MA];

void dfs(int u, int c) {
	if (vis[u]++) {
		if (col[u] != c) {
			isBi = false;
		}
		return;
	}
	ccSize++;
	col[u] = c;
	each(v, G[u]) {
		dfs(v, 1 - c);
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

	int N, M;
	cin >> N >> M;
	rep(i, M) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	ll isolated = 0, bi = 0, other = 0;
	rep(i, N)if (!vis[i]) {
		isBi = true;
		ccSize = 0;
		dfs(i, 0);
		
		if (ccSize == 1)isolated++;
		else if (isBi)bi++;
		else other++;
	}

	ll ans = 0;
	// 少なくとも１つが孤立点
	ans += isolated * (N - isolated) * 2 + isolated*isolated;
	// 孤立点なし、両方が二部グラフ
	ans += bi * bi * 2;
	// 孤立点なし、どちらかが二部グラフではない
	ans += bi*other * 2 + other*other;

	cout << ans << endl;
}
