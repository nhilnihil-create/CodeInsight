#include <iostream>
#include <cstdio>
using namespace std;
int n, m, a[100010];
int main () {
	int t = 0;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf ("%d", &a[i]);
		if (a[i] & 1) t++;
	}
	if (t > 2) { printf ("Impossible\n"); return 0; };
	for (int i = 1; i <= m; i++) if (a[i] & 1) {
		if (t == 2) swap (a[i], a[1]);
		else swap (a[i], a[m]);
		t--;
	}
	for (int i = 1; i <= m; i++) printf ("%d%c", a[i], " \n"[i == m]);
	if (m == 1) {
		if (a[1] == 1) printf ("1\n1\n");
		else printf ("2\n%d 1\n", a[1] - 1);
	} else if (m == 2) {
		if (a[1] == 1) {
			if (a[2] == 1) printf ("1\n2\n");
			else printf ("2\n2 %d\n", a[2] - 1);
		} else printf ("2\n%d %d\n", a[1] - 1, a[2] + 1);
	} else {
		if (a[1] == 1) {
			printf ("%d\n", m - 1);
			for (int i = 2; i < m; i++) printf ("%d ", a[i]);
			printf ("%d\n", a[m] + 1);
		} else {
			printf ("%d\n", m);
			printf ("%d ", a[1] - 1);
			for (int i = 2; i < m; i++) printf ("%d ", a[i]);
			printf ("%d\n", a[m] + 1);
		}
	}
	return 0;
}