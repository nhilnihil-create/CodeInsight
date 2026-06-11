#include <stdio.h>
int n, f;
char s[100001];
int x[100001];
int a[100002];
int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o')x[i] = 0;
		if (s[i] == 'x')x[i] = 1;
	}
	x[n] = x[0];
	for (int e = 0; e < 4; e++) {
		a[0] = e / 2; a[1] = e % 2;
		for (int i = 1; i <= n; i++) {
			a[i + 1] = (a[i] + a[i - 1] + x[i]) % 2;
		}
		if (a[0] == a[n] && a[1] == a[n + 1]) {
			f = 1;
			for (int i = 0; i < n; i++) {
				if (a[i])s[i] = 'W';
				else s[i] = 'S';
			}
			break;
		}
	}
	if (f)printf("%s\n", s);
	else printf("-1\n");
}