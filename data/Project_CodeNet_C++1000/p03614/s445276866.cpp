#include<cstdio>
int n, w[101000], ck[101000], r;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		if (w[i] == i)ck[i] = 1;
	}
	for (i = 1; i < n; i++) {
		if (ck[i] && ck[i + 1]) {
			ck[i] = ck[i + 1] = 0;
			r++;
		}
	}
	for (i = 1; i <= n; i++)r += ck[i];
	printf("%d\n", r);
}