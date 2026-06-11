#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int x[2], n, m;
vector<int> g[100001];
bool vis[100001], C[100001];

pair<int, int> go(int v, int c = 0){
	vis[v] = true;
	C[v] = c;
	pair<int, int> an(1, c);
	f(i, 0, g[v].size()){
		int u = g[v][i];
		if (vis[u]){
			if (c ^ 1 ^ C[u])an.second = -1;
			continue;
		}
		pair<int, int> t = go(u, c ^ 1);
		an.first += t.first;
		if (t.second == -1)an.second = -1;
		else if (an.second != -1)an.second += t.second;
	}
	return an;
}

int main(){
	scanf("%d%d", &n, &m);
	f(i, 0, m){
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ll an = (ll)n * n;
	int z = 0, w = 0;
	f(i, 1, n + 1)if (!vis[i] && !g[i].empty()){
		pair<int, int> t = go(i);
		if (t.second == -1)x[0] += t.first, ++w;
		else x[0] += t.second, x[1] += t.first - t.second, ++z;
	}
	an += (ll)z * z << 1;
	an += (ll)z * w << 1;
	an += (ll)w * w;
	an -= (ll)x[0] * x[0] + (ll)x[1] * x[1] + (ll)x[0] * x[1] * 2;
	printf("%lld\n", an);
}
