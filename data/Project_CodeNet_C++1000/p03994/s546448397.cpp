#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, K, a[N];
char s[N];
int main() {
	scanf("%s %d", s + 1, &K);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = s[i] - 'a';
		if (a[i]) {
			if ((26 - a[i]) <= K) {
				K -= (26 - a[i]);
				a[i] = 0;
			}
		}
	}
	K %= 26;
	if (K) {
		a[n] = (a[n] + K) % 26;
	}
	for (int i = 1; i <= n; i++) putchar(a[i] + 'a');
	return 0;
}