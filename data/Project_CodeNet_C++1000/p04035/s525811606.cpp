#include <bits/stdc++.h>

using namespace std;
#define K 400001

int a[K], n, l;

int main() {
	scanf("%d%d", &n, &l);
	
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	int ok = -1;
	
	for (int i = 1; i < n; i++) {
		int z = a[i] + a[i + 1];
		
		if (z >= l) {
			ok = i;	
		}
	}
	
	if (ok == -1) {
		puts("Impossible");
		return 0;	
	}
	
	puts("Possible");
	for (int i = 1; i < ok; i++) printf("%d\n", i);
	
	for (int i = n - 1; i > ok; i--) printf("%d\n", i);
	
	printf("%d\n", ok);
}