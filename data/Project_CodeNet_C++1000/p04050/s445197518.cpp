#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 111;

bool buf;
int n, m;
int a[maxn];

int main() {

	buf = scanf("%d %d", &n, &m);

	int o = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", a+i);
		o += (int)(a[i]&1);
		if (a[i]&1) {
			if (o == 1)
				swap(a[i], a[1]);
			else if (o == 2)
				swap(a[i], a[m]), i--, m--;
			else {
				puts("Impossible"); 
				return 0;
			}
		}
	}
	m += (o==2);

	for (int i = 1; i <= m; i++) {
		printf("%d%c", a[i], (i == m ? '\n' : ' '));
	}

	if (m == 1) {
		if (n == 1) puts("1\n1");
		else printf("2\n%d 1\n", n-1);
		return 0;
	}

	printf("%d\n%d ", m - (int)(a[m]==1), a[1]+1);
	for (int i = 2; i < m; i++) {
		printf("%d ", a[i]);
	}
	if (a[m] != 1)
		printf("%d", a[m]-1);
	putchar('\n');

	return 0;
}