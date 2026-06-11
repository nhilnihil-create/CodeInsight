#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
using namespace std;
typedef long long ll;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"in%s.txt",s);
	freopen(str,"r",stdin);
//	sprintf(str,"out%s.txt",s);
//	freopen(str,"w",stdout);
	#endif
}
inline int rd()
{
	static int x,f;
	x=0;f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=100010;
int n,K,a[N],b[N],bin[31];

int main()
{
	bin[0]=1;fo(i,1,30)bin[i]=bin[i-1]<<1;
	n=rd();K=rd();
	fo(i,1,n)a[i]=rd(),b[i]=rd();
	ll ans=0;
	fo(i,1,n)if((a[i]|K)==K)ans+=b[i];
	fo(i,1,30){
		if((bin[i]&K)==0)continue;
		int hh=(K^bin[i])|(bin[i]-1);
		ll res=0;
		fo(i,1,n)if((hh|a[i])==hh)res=res+(ll)b[i];
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
