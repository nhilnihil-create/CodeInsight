#include<cstdio>
#include<cstring>
#include<iostream>
#define inf 0x7fffffffffffffff
using namespace std;
typedef long long lint;
const lint Mod=1e9+7,Maxn=1e5+3;
int main()
{
	lint Ans=1,K=0,N,Data;
	scanf("%lld",&N);
	while(N--)
	{
		scanf("%lld",&Data);
		K++;
		if(Data<(2*K-1))
		{
			Ans=(Ans*K)%Mod;
			K--;
		}
	}
	for(int i=2;i<=K;i++)
	Ans=(Ans*i)%Mod;
	printf("%lld",Ans);
	return 0;
}