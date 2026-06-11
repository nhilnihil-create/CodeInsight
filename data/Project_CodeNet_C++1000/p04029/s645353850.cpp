#include <stdio.h>

int main() {
	int n;	
	scanf("%d", &n);
	long long int tot = 0;
	
	for(int i = 1; i <= n; i++) {
		tot += i;	
	}
	printf("%lld\n", tot);
	
	return 0;
}
