#include<cstdio>
#define lli long long int
int a,b,c;
inline lli mn(lli x,lli y){return x<y?x:y;}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(a&b&c&1)return printf("%lld",mn(mn(1ll*a*b,1ll*a*c),1ll*b*c)),0;
	return printf("0"),0;
}