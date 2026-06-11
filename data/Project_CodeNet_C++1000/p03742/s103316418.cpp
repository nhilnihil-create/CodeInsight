#include <bits/stdc++.h>

typedef long long LL;

int main() {
	LL X, Y;
	while(~scanf("%lld%lld", &X, &Y)) {
		bool ans = X + 1 == Y || X == Y || X == Y + 1; 
		printf("%s\n", !ans ? "Alice" : "Brown");
	}
	return 0;
}