#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> piii;

vector <int> from[100010];
vector <piii> query;
int ans[100010];
int max_d[100010];

void print(int x, int d, int c){
//	cout << x << " " << d << " " << c << endl;
	if (max_d[x] >= d) return ;
	max_d[x] = d;
	if (ans[x] == 0) ans[x] = c;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		print(v, d - 1, c);
	}
}

int main(){
	int n, m, q;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		int v, d, c;
		scanf("%d%d%d", &v, &d, &c);
		query.push_back(mp(v, mp(d, c)));
	}
	reverse(query.begin(), query.end());
	memset(max_d, -1, sizeof(max_d));
	for (int i = 0; i < q; i++){
		piii t = query[i];
		print(t.fi, t.se.fi, t.se.se);
	}
	for (int i = 1; i <= n; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
