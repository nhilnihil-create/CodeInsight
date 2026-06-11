#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
#define LL long long
using namespace std;
const int N=1e5+10;
int n,k,a[N],b[N];
LL ans;
inline int read(){
	char ch=getchar(); int x=0, f=1;
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;}
template<typename I>inline I mx(const I a,const I b){return a>b ? a : b;}
int main()
{
	//freopen("IntegerotS.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(); k=read();
	for(RG int i=1;i<=n;i++)
	{
		a[i]=read(); b[i]=read();
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
	//fclose(stdin); fclose(stdout);
	return 0;
}