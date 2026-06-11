#include <bits/stdc++.h>

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	if(x == 1 || x == 2 * n - 1) {
		printf("No\n");
	} else if(n > 2) {
		printf("Yes\n");
		if(x != 2) {
			int ptr = 1;
			for(int i = 1; i < n - 1; ++i, ++ptr) {
				if(ptr == x - 2) ptr = x + 2;
				printf("%d\n", ptr);
			}
			printf("%d\n%d\n%d\n%d\n", x - 2, x, x + 1, x - 1);
			for(int i = 1; i < n - 2; ++i, ++ptr) {
				if(ptr == x - 2) ptr = x + 2;
				printf("%d\n", ptr);
			}
		} else {
			int ptr = 1;
			for(int i = 1; i < n - 1; ++i, ++ptr) {
				if(ptr == x - 1) ptr = x + 3;
				printf("%d\n", ptr);
			}
			printf("%d\n%d\n%d\n%d\n", x + 2, x, x - 1, x + 1);
			for(int i = 1; i < n - 2; ++i, ++ptr) {
				if(ptr == x - 1) ptr = x + 3;
				printf("%d\n", ptr);
			}
		}
	} else {
		printf("Yes\n1\n2\n3\n");
	}
	return 0;
}