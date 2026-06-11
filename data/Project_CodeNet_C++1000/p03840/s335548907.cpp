#include<cstdio>
int I,O,T,J,L,S,Z,now,ans;
int main()
{
	scanf("%d%d%d%d%d%d%d",&I,&O,&T,&J,&L,&S,&Z);
	now=(I&1)+(J&1)+(L&1);
	if(now>=2&&I&&J&&L)
	{
		--I,--J,--L;
		ans+=3;
	}return printf("%lld\n",(long long)ans+O+I/2*2+J/2*2+L/2*2),0;
}