#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#define N 200005
#define PII pair<int, int>
using namespace std;

int n, k, l, c, a[N], b[N];
map<PII, int> m;
vector<int> va[N], vb[N];

void f(int p) {
	int i;
	if (a[p]) return;
	a[p] = c;
	for (i = 0; i < va[p].size(); i++) f(va[p][i]);
}

void g(int p) {
	int i;
	if (b[p]) return;
	b[p] = c;
	for (i = 0; i < vb[p].size(); i++) g(vb[p][i]);
}

int main()
{
	int i, t1, t2;
	cin >> n >> k >> l;
	for (i = 0; i < k; i++) {
		scanf("%d %d", &t1, &t2);
		va[t1].push_back(t2), va[t2].push_back(t1);
	}
	for (i = 0; i < l; i++) {
		scanf("%d %d", &t1, &t2);
		vb[t1].push_back(t2), vb[t2].push_back(t1);
	}
	for (i = 1, c = 0; i <= n; i++) if (!a[i]) c++, f(i);
	for (i = 1, c = 0; i <= n; i++)
		if (!b[i])
			c++, g(i);
	for (i = 1; i <= n; i++) m[PII(a[i], b[i])]++;
	for (i = 1; i <= n; i++) {
		if (a[i] == 0 && b[i] == 0) printf("1 ");
		else printf("%d ", m[PII(a[i], b[i])]);
	}
    return 0;
}