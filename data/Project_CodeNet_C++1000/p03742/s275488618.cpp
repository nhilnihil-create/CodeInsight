#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
int main()
{
	ll a, b;
	scanf("%lld%lld", &a, &b);
	printf((abs(a - b) <= 1) ? "Brown\n" : "Alice\n");
}