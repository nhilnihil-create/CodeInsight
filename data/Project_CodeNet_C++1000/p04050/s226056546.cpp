#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int n, m;
int a[100010], b[100010], cnt;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch=='-') f=-1;
	for(; isdigit(ch); ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x * f;
}

int main() {
	int i;
	n = read(), n = read();
	for(i = 1; i <= n; i++) a[i] = read();
	for(i = 2; i < n; i++) {
		if(a[i] & 1) {
			if(a[1] & 1) {
				if(a[n] & 1) break;
				swap(a[n], a[i]);
			}
			else swap(a[i], a[1]);
		}
	}
	if(i < n) {
		printf("Impossible\n");
		return 0;
	}
	if(n == 1) {
		if(a[1] == 1) b[cnt = 1] = 1;
		else {
			b[1] = a[1]-1;
			b[cnt=2] = 1;
		}
	}
	else {
		if(a[1] != 1) b[++cnt] = a[1]-1;
		for(i = 2; i < n; i++) b[++cnt] = a[i];
		b[++cnt] = a[n]+1;
	}
	for(i = 1; i <= n; i++) printf("%d ", a[i]);
	printf("\n");
	printf("%d\n", cnt);
	for(i = 1; i <= cnt; i++) printf("%d ", b[i]);
	printf("\n");
	return 0;
}
