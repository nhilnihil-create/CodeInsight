#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 7;

vector<int> G[maxn];

int C[maxn];

ll B,N,S;
bool ok;

int dfs(int x) {
	int sz = 1;

	for (int j = 0; j < G[x].size(); j++) {
		int z = G[x][j];
		if (C[z] >= 0) {
			if (C[z] == C[x]) ok = false;
		} else {
			C[z] = 1 - C[x];
			sz += dfs(z);
		}
	}

	return sz;
}


int main() {
	int n,m; scanf("%d %d",&n,&m); B = N = S = 0;

	fill(C, C+maxn, -1);
	fill(G, G+maxn, *new vector<int>());

	for (int i = 0; i < m; i++) {
		int x,y; scanf("%d %d",&x, &y);
		G[x].pb(y); G[y].pb(x);
	}

	for (int i = 1; i <= n; i++) {
		if (C[i] >= 0) continue;
		
		C[i] = 0;

		//cout<<" ;; "<<i<<endl;

		ok = true;
		int sz = dfs(i);

		//cout<<"sz :"<<sz<<endl;

		if (sz == 1) S++;
		else if (ok) B++;
		else N++;
	}

	//cout<<"B = "<<B<<" , N = " <<N<<

	//ll N = n;

	//cout<<B<<" , "<<N<<" , "<<S<<endl;

	ll ans = S * (n - S) * 2 + S * S; // single nodes
	ans += N + B + B; // self pairs

	ans += B * N * 2 + N * (N-1);	// with nonbipartites, different components
	
	ans += B * (B - 1) * 2;  // between bipartites

	printf("%lld\n",ans);
}
