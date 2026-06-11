#include <iostream>
#include <cstdio>
#include <map>
#define N 200005
#define PI pair<int, int>
#define F first
#define S second
using namespace std;

int n, m1, m2, a1[N], a2[N];
map<PI, int> v;
int f(int p, int q[]) {
	if (q[p] == p) return p;
	return q[p] = f(q[p], q);
}

int main()
{
	int i, t1, t2;
	cin >> n >> m1 >> m2;
	for (i = 1; i <= n; i++) a1[i] = i;
	for (i = 1; i <= n; i++) a2[i] = i;
	while (m1--) {
		scanf ("%d %d", &t1, &t2);
		t1 = f(t1, a1);
		t2 = f(t2, a1);
		if (t1 != t2) a1[t1] =t2;
	}
	while (m2--) {
		scanf ("%d %d", &t1, &t2);
		t1 = f(t1, a2);
		t2 = f(t2, a2);
		if (t1 != t2) a2[t1] =t2;
	}
	for (i = 1; i <= n; i++) {
		f(i, a1);
		f(i, a2);
		v[PI(a1[i], a2[i])]++;
	}
	for (i = 1; i <= n; i++) {
		printf("%d ", v[PI(a1[i], a2[i])]);
	}
    return 0;
}
