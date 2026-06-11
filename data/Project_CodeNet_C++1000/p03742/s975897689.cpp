#include <stdio.h>

typedef long long lint;

int main() {
	lint X, Y;

	scanf("%lld%lld", &X, &Y);
	if(-((X + Y) % 2) <= X - Y && X - Y <= (X + Y) % 2) printf("Brown");
	else printf("Alice");
	return 0;
}
