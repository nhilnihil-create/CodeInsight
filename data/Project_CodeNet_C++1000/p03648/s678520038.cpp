#include <cstdio>
typedef long long int lli;

int main()
{
	lli K;
	scanf("%lld", &K);
	lli p = K / 50;
	lli q = K % 50;
	printf("50\n");
	for (int i = 0; i < q; i++)
		printf("%lld ", 100 - q + p);
	for (int i = 0; i < 50 - q; i++)
		printf("%lld ", 49 - q + p);
}