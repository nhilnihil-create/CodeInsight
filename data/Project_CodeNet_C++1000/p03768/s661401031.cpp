#include <bits/stdc++.h>
using namespace std;

struct Point{
	int v, d, c;
};

vector <int> from[100010];
vector <Point> a;
int ans[100010], max_d[100010];

inline void paint(int x, int dis, int num, int c){
	if (dis + max_d[x] >= num) return ;
	max_d[x] = max(max_d[x], num - dis);
	if (ans[x] == 0) ans[x] = c;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		paint(v, dis + 1, num, c);
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	int q;
	scanf("%d", &q);
	a.resize(q);
	for (int i = 0; i < q; i++){
		scanf("%d%d%d", &a[i].v, &a[i].d, &a[i].c);
	}
	reverse(a.begin(), a.end());
	memset(max_d, -1, sizeof(max_d));
	for (int i = 0; i < q; i++){
//		cout << i << endl;
		paint(a[i].v, 0, a[i].d, a[i].c);
	}
	for (int i = 1; i <= n; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
