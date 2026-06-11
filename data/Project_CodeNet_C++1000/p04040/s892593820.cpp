#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<vector>
#include<queue>
#include<map>
#include<deque>
#include<stack>
#include<algorithm>
#define N 200005
using namespace std;
const int INF=0x7fffffff;
const double Pi=acos(-1);
const long long Mod=1e9+7;
long long F[N],Inv[N];
long long Quick_Pow(long long X,long long K)
{
	long long Ans=1;
	while(K)
	{
		if(K&1)Ans=Ans*X%Mod;
		K>>=1;
		X=X*X%Mod;
	}
	return Ans;
}
long long Get_Inv(long long X)
{
	return Quick_Pow(X,Mod-2);
}
long long C(long long n,long long m)//ÇóC(n,m) 
{
	return F[n]*(Inv[m]*Inv[n-m]%Mod)%Mod;
}
int main()
{
	int i;
	long long n,m,A,B,Maxx;
	scanf("%lld%lld%lld%lld",&n,&m,&A,&B);
	Maxx=n+m;
	F[0]=1;Inv[0]=1;
	for(i=1;i<=Maxx;i++)
	{
		F[i]=F[i-1]*i%Mod;
		Inv[i]=Get_Inv(F[i]);
	}//ÌáÇ°´æ´¢ºÃiµÄ½×³ËºÍ¶ÔÓ¦µÄÄæÔª 
	long long Ans=0;
	for(i=1;i<=n-A;i++)//(1,1)->(i,B)->(i,B+1)->(n,m) 
	{
		Ans=(Ans+C(i+B-2,B-1)*C(n-i+m-B-1,m-B-1)%Mod)%Mod;
	}
	printf("%lld\n",Ans);
	return 0;
}