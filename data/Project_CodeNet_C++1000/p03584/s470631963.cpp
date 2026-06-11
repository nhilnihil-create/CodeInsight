#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
#define LL long long
using namespace std;
const int N=1e5+10;
int n,k,a[N],b[N];
LL ans;
template<typename I> inline void read(I &ot){
	I ch=getchar(), x=0, f=1;
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	ot=x*f;}
template<typename I, typename... U> inline void read(I &x, U&... y){read(x), read(y...);}
template<typename I> inline I mx(const I a,const I b){return a>b ? a : b;}
int main()
{
	//freopen("IntegerotS.in","r",stdin);
	read(n,k); 
	for(RG int i=1;i<=n;i++)
	{
		read(a[i],b[i]);
		if((a[i]&k)==a[i]) ans+=b[i];
	}
	for(RG int i=0;i<=30;i++)
	{
		if(((1<<i)&k)==0) continue;
		int tt=(k^(1<<i))|((1<<i)-1); LL re=0;
		for(RG int i=1;i<=n;i++) if((a[i]&tt)==a[i]) re+=b[i];
		ans=mx(ans,re);
	}
	printf("%lld\n",ans);
	return 0;
}