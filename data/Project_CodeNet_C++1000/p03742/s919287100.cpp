#include<cstdio>
#include<cmath>

int main()
{
	long long x,y;
	scanf("%lld %lld",&x,&y);
	printf(fabs(x-y)<2 ? "Brown" : "Alice");
	return 0;	
}