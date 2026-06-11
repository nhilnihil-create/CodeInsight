#include <cstdio>
int n, s, a;
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a);
		if(a==i) {
			s++;
			scanf("%*d"), i++;
		}
	}
	printf("%d", s);
	return 0;
}