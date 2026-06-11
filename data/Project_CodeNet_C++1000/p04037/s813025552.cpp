#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 1;
int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}
void put(int x) {
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

int a[N];

int main() {
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1), reverse(a + 1, a + n + 1);
	int p;
	for(int i = 1; i <= n; i++) if(i + 1 > a[i + 1]) {p = i; break;}
	int q = p;
	while(q < n && a[q + 1] >= p) q++;
	int g;
	if(p == q) g = (a[p] - p) & 1;
	else if(a[p] == p) g = (q - p) & 1;
	else g = ((a[p] - p) & 1) | ((q - p) & 1);
	if(g) puts("First");
	else puts("Second");
	return 0;
}