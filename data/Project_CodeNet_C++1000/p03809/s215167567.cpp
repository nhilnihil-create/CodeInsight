#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define psp printf(" ")
#define endc printf("\n")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e5 + 7; 

ll a[maxn];
ll b[maxn];
vector<int> G[maxn];
bool ok;

void dfs(int x,int pi) {
	if (G[x].size() > 1) a[x]*=2;
	for (int j = 0; j < G[x].size(); j++) {
		int y = G[x][j];
		if (y == pi) continue;
		dfs(y,x);
		if (!ok) return;
	}

	ll l = a[x] - b[x];
	if (pi < 0) {
		if (l != 0) ok = false;
		return;
	}
	if ((l > a[pi]/2) || (l + b[pi] > a[pi]) || (G[x].size() > 1 && l > a[x]/2)) { ok = false; return; }
	b[pi] += l;
}

int main() {
	int n; sd(n); ok = true;
	for (int i = 1; i <= n; i++) {
		sl(a[i]); b[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int x,y; sd(x); sd(y);
		G[x].pb(y); G[y].pb(x);
	}
	if (n == 2) {
		printf((a[1] == a[2]) ? "YES\n" : "NO\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (G[i].size() > 1) {
			dfs(i,-1); break;
		}
	}
	printf(ok?"YES\n":"NO\n");
}
