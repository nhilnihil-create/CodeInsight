#include<stdio.h>
long long x, y, z;
int main() {
	scanf("%lld%lld", &x, &y);
	z = x + y;
	if(x % 3 != 0 && y % 3 != 0 && z % 3 != 0) printf("Impossible\n");
    else printf("Possible\n");
    return 0;
}