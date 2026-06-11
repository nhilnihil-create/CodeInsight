#include<bits/stdc++.h>
using namespace std;
#define MAXN	1000005
#define P	1000000007
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
long long f[MAXN], s[MAXN], n;
int main() {
	read(n);
	f[0] = 1; f[1] = n;
	s[0] = 1; s[1] = n + 1;
	for (int i = 2; i <= n; i++) {
		f[i] = (s[i - 1] + (n + 1 - i) + (n - 1) * (n - 1) - f[i - 2] + P) % P;
		s[i] = (s[i - 1] + f[i]) % P;
	}
	cout << f[n] << endl;
	return 0;
}