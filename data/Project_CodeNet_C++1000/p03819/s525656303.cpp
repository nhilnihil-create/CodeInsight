#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 1000005
using namespace std;

typedef long long ll;

int n, m, kac, bas[N], son[N], fen[N];
vector < int > g[N];

void up(int x, int y){
	for(; x < N; x += x&-x)
		fen[x] += y;
}

int qu(int x){
	int ans = 0;
	for(; x > 0; x -= x&-x)
		ans += fen[x];
	return ans;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d %d",&n ,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d %d",bas + i, son + i);
		g[son[i] - bas[i] + 1].pb(i);
	}
	kac = n;
	for(int i = 1; i <= m; i++){
		int ans = kac;
		for(int j = i; j <= m; j += i)
			ans += qu(j);
		printf("%d\n", ans);
		for(int j = 0; j < g[i].size(); j++){
			int k = g[i][j];
			up(bas[k], 1);
			up(son[k] + 1, -1);
			kac--;
		}
	}
	return 0;
}