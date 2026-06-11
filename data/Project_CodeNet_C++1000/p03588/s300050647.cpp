#include <cstdio>
int n, a, b, ma, mb=2e9;
int main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &a, &b);
		if(b<mb) mb=b, ma=a;
	}
	printf("%d", ma+mb);
}