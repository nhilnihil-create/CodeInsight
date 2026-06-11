#include<cstdio>
int main() {
	long long X, Y;
	scanf("%lld%lld", &X, &Y);
	puts(X == Y || X == Y + 1 || Y == X + 1 ? "Brown" : "Alice");
}