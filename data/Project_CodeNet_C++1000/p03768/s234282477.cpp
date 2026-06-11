#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 100005 ////////////////////////////////////
using namespace std;

int n, m, Q, d[N], gi[N], di[N], num[N], ans[N];
vector<int> a[N];
void f(int p, int q, int w) {
	int i;
	if (d[p] >= q) return;
	d[p] = q;
	if (ans[p] == 0) ans[p] = w;
	for (i = 0; i < a[p].size(); i++) f(a[p][i], q - 1, w);
}
int main()
{
	int i, t1, t2;
	cin >> n >> m;
	while (m--) {
		scanf ("%d %d", &t1, &t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	cin >> Q;
	for (i = 1; i <= Q; i++) {
		scanf ("%d %d %d", &gi[i], &di[i], &num[i]);
	}
	memset(d, -1, sizeof(d));
	for (i = Q; i >= 1; i--) {
		f(gi[i], di[i], num[i]);
	}
	for (i = 1; i<= n; i++) printf("%d\n", ans[i]);
    return 0;
}
