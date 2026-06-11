#include <cstdio>
using namespace std;

const int N = 1e5 + 100;
int n, m, flag, a[N], b[N];

inline void swap(int &a, int &b) {int t = a; a = b, b = t;}
template <class T> inline void in(T &x) {
	x = 0; int f = 1; char ch = getchar();
	for (; ch<'0' || ch>'9';) {if (ch=='-') f=-1; ch = getchar();}
	for (; ch>='0' && ch<='9';) x = x*10 + ch-'0', ch = getchar();
	x *= f;
}

int main() {
	int od1 = 0, od2 = 0; in(n), in(m);
	for (int i = 1; i <= m; ++i) in(a[i]);
	for (int i = 1; i <= m; ++i)
		if (a[i] & 1) {
			if (!od1) od1 = i;
			else if (!od2) od2 = i;
			else {puts("Impossible"); return 0;}
		}
	if (od1) swap(a[1], a[od1]);
	if (od2) swap(a[m], a[od2]);
	if (m == 1) {
		if (a[1] == 1) {printf("1\n1\n1"); return 0;}
		printf("%d\n2\n1 %d", a[1], a[1] - 1); return 0;
	}
	for (int i = 1; i <= m; ++i) printf("%d ", a[i]); puts("");
	printf("%d\n%d", a[m] == 1 ? m - 1 : m, a[1] + 1);
	for (int i = 2; i <= m - 1; ++i) printf(" %d", a[i]);
	if (a[m] > 1) printf(" %d\n", a[m] - 1);
	return 0;
}