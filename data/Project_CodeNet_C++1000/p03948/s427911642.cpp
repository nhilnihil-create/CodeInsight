#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
#define LL long long
using namespace std;
int n;
LL a,m,num,maxx,minn;
template<typename I> inline void read(I &ot){
	I ch=getchar(), x=0, f=1;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();	}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();	}
	ot=x*f;}
template<typename I, typename... U> inline void read(I &x,U&... y){read(x); read(y...);}
template<typename I>inline I mi(const I&a,const I&b){return a<b ? a : b;}
template<typename I>inline I mx(const I&a,const I&b){return a>b ? a : b;}
int main()
{
	//freopen("An Invisible Hand.in","r",stdin);
	//freopen(".out","w",stdout);
	read(n,m); m/=2; minn=3e18;
	for(RG int i=1;i<=n;i++)
	{
		read(a); minn=mi(minn,a);
		if((a-minn)*m>maxx) maxx=(a-minn)*m, num=1;
		else if((a-minn)*m==maxx) num++;
	}
	printf("%lld\n",num);
	//fclose(stdin); fclose(stdout);
	return 0;
}
