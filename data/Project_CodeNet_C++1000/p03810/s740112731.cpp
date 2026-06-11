#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, a[MAXN];
int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
bool work() {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += (a[i] & 1) ^ 1;
	if (cnt & 1) return true;
	if (cnt != n - 1) return false;
	for (int i = 1; i <= n; i++)
		if (a[i] % 2 != 0) {
			a[i]--;
			if (a[i] == 0) return false;
		}
	int g = a[1];
	for (int i = 2; i <= n; i++)
		g = gcd(g, a[i]);
	for (int i = 1; i <= n; i++)
		a[i] /= g;
	return !work();
}
bool check(int x, int y) {
	if ((x + y) % 2) return true;
	else return false;
}
int main() {
	read(n);
	if (n == 1) {
		printf("Second\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		read(a[i]);
	if (n == 2) {
		if (check(a[1], a[2])) printf("First\n");
		else printf("Second\n");
		return 0;
	}
	if (work()) printf("First\n");
	else printf("Second\n");
	return 0;
}