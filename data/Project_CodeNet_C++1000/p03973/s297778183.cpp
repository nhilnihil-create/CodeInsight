#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
using namespace std;
int n,cnt=1;
long long ans;
template<typename I> inline void read(I &ot){
	I ch=getchar(), x=0, f=1;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();	}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();	}
	ot=x*f;}
template<typename I, typename... U> inline void read(I &x,U&... y){read(x); read(y...);}
int main()
{
	//freopen("Greedy Customers.in","r",stdin);
	read(n);
	for(RG int i=1,a;i<=n;i++)
	{
		read(a);
		if(a<cnt) continue;
		if(a==cnt) cnt++;
		else
		{
			if(a%cnt==0) ans+=a/cnt-1;
			else ans+=a/cnt;
		}
		if(cnt==1) cnt++;
	}
	printf("%lld\n",ans);
	return 0;
}