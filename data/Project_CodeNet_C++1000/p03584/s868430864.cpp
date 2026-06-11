#include <stdio.h>
int n, kk, f;
int k[30];
int u[30];
int a[100000][30];
long long b[100000];
long long s, ans;
int main() {
	scanf("%d%d", &n, &kk);
	for (int i = 0; i < 30; i++) {
		k[i] = kk % 2;
		kk /= 2;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d%lld", &kk, b + i);
		for (int j = 0; j < 30; j++) {
			a[i][j] = kk % 2;
			kk /= 2;
		}
	}
	s = 0;
	for (int m = 0; m < 30; m++)u[m] = k[m];
	for (int i = 0; i < n; i++) {
		f = 1;
		for (int j = 0; j < 30; j++) {
			if (a[i][j] == 1 && u[j] == 0)f = 0;
		}
		if (f)s += b[i];
	}
	if (s > ans)ans = s;
	for (int l = 0; l < 30; l++) {
		s = 0;
		if (k[l] == 0) {
			for (int m = 0; m < 30; m++)u[m] = k[m];
		}
		else {
			for (int m = 0; m < l; m++) u[m] = 1;
			u[l] = 0;
			for (int m = l + 1; m < 30; m++)u[m] = k[m];
		}
		for (int i = 0; i < n; i++) {
			f = 1;
			for (int j = 0; j < 30; j++) {
				if (a[i][j] == 1 && u[j] == 0)f = 0;
			}
			if (f)s += b[i];
		}
		if (s > ans)ans = s;
	}
	printf("%lld\n", ans);
}