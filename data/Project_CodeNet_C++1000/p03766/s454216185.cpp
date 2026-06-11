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
const int N=1000010,mod=1000000007;
int n,f[N],sum=0,tmp=0;

inline int pls(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mns(int a,int b){return a<b?a-b+mod:a-b;}
inline int mul(int a,int b){return (ll)a*b%mod;}

int main()
{
	n=rd();
	if(n<=2)return printf("%d\n",n*n),0;
	int ans=0;
	f[n]=1;sum=0;ans=pls(mul(f[n], mul(n-1, n-1)), mul(f[n], 2));
	of(i,n-1,1){
		f[i]=sum;
		f[i]=pls(f[i],f[i+1]);
		sum=pls(sum,f[i+2]);
		if(i>1)ans=pls(ans,pls(mul(f[i],mul(n-1,n-1)),mul(f[i],min(n-i+2,n-1))));
	}
	ans=pls(ans,mul(f[1],n));
	printf("%d\n",ans);
	return 0;
}
