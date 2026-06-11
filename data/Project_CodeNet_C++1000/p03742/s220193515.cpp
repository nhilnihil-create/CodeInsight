#include<cstdio>
long long x,y;
long long ww(long long a)
{
	if(a<0)a=-a;
	return a;
}
int main()
{
	scanf("%lld%lld",&x,&y);
	if(ww(x-y)<2)
		printf("Brown");
	else printf("Alice");
}