#include<cstdio>
#include<algorithm>
int main() {
	long long x, y;
	scanf("%lld%lld", &x, &y);
	if (std::abs(x - y) > 1)printf("Alice");
	else printf("Brown");
	return 0;
}