#include <bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f3f // -Wall
using namespace std;

template<class T> inline
void read(T& x) {
	int f = 1; x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}

/*============ Header Template ============*/

const int N = 100000 + 5;

int n, m, cnt;
int a[N], b[N];

int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) read(a[i]);
	if (m == 1) {
		printf("%d\n", a[1]);
		int cnt = (a[1] == 1) ? 1 : 2;
		printf("%d\n", cnt);
		if (cnt == 1) printf("%d\n", 1);
		else printf("%d %d\n", a[1] - 1, 1);
		return 0;
	}
	if (m == 2) {
		printf("%d %d\n", a[1], a[2]);
		int cnt = (a[1] == 1) ? 1 : 2;
		printf("%d\n", cnt);
		if (cnt == 1) printf("%d\n", n);
		else printf("%d %d\n", a[1] - 1, a[2] + 1);
		return 0;
	}
	for (int i = 1; i <= m; i++) if (a[i] & 1) cnt++;
	if (cnt > 2) {printf("Impossible\n"); return 0;}
	for (int i = 1; i <= m; i++) {
		if (a[i] & 1) {
			if (cnt == 2) swap(a[1], a[i]);
			else if (cnt == 1) swap(a[m], a[i]);
			cnt--;
		}
	}
	for (int i = 1; i <= m; i++) printf("%d ", a[i]); printf("\n");
	for (int i = 1; i <= m; i++) b[i] = a[i]; b[1]++, b[m]--;
	if (b[m] == 0) m--;
	printf("%d\n", m);
	for (int i = 1; i <= m; i++) printf("%d ", b[i]); printf("\n");
	return 0;
}