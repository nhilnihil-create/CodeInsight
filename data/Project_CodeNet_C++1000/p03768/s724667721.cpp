#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define N 100005
using namespace std;
 
int n, m, q, b1[N], b2[N], b3[N], c[N], d[N];
vector<int> a[N];
 
void f(int p, int q, int r) {
	int i;
	if (q <= d[p]) return;
	d[p] = q;
	if (!c[p]) c[p] = r;
	for (i = 0; i < a[p].size(); i++) f(a[p][i], q - 1, r);
}
 
int main()
{
	int i, t1, t2;
	cin >> n >> m;
	memset(d, -1, sizeof(d));
	for (i = 0; i < m; i++) {
		scanf("%d %d", &t1, &t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	cin >> q;
	for (i = 0; i < q; i++) scanf("%d %d %d", &b1[i], &b2[i], &b3[i]);
	for (i = q - 1; i >= 0; i--) {
		f(b1[i], b2[i], b3[i]);
	}
	for (i = 1; i <= n; i++) printf("%d\n", c[i]);
    return 0;
}