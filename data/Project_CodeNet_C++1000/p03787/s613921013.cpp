#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

vector <int> E[100010];
int vis[100010];
int color[100010];

int dfs(int x, int c){
	int res = 1;
	vis[x] = 1, color[x] = c;
	for(int e : E[x]){
		if(vis[e] == 0)res &= dfs(e, 3-c);
		else if(color[e] != 3 - c)res = 0;
	}
	return res;
}

int deg[100010];

void solve(){
	int n, m; cin >> n >> m;
	ll ans = 0;
	rep(i, m){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
		deg[x]++, deg[y]++;
	}
	int a = 0, b = 0;
	for(int i=1;i<=n;i++)if(deg[i] > 0 && !vis[i]){
		++a;
		b += dfs(i, 1);
	}
	ans = (ll)n * n;
	int c = 0;
	for(int i=1;i<=n;i++)if(deg[i] > 0)++c;
	ans -= (ll)c * c;
	ans += (ll)a * a + (ll)b * b;
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
