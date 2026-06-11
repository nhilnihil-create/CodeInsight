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
int f(int p) {
	if (a1[p] == p) return p;
	return a1[p] = f(a1[p]);
}

int g(int p) {
	if (a2[p] == p) return p;
	return a2[p] = g(a2[p]);
}

int main()
{
	int i, t1, t2;
	cin >> n >> m1 >> m2;
	for (i = 1; i <= n; i++) a1[i] = i;
	for (i = 1; i <= n; i++) a2[i] = i;
	while (m1--) {
		scanf ("%d %d", &t1, &t2);
		t1 = f(t1);
		t2 = f(t2);
		if (t1 != t2) a1[t1] =t2;
	}
	while (m2--) {
		scanf ("%d %d", &t1, &t2);
		t1 = g(t1);
		t2 = g(t2);
		if (t1 != t2) a2[t1] =t2;
	}
	for (i = 1; i <= n; i++) {
//			printf("%d %d\n", a1[i], a2[i]);
		t1 = f(a1[i]);
		t2 = g(a2[i]);
		v[PI(t1, t2)]++;
	}
	for (i = 1; i <= n; i++) {
		t1 = f(a1[i]);
		t2 = g(a2[i]);
		printf("%d ", v[PI(t1, t2)]);
	}
    return 0;
}
