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
inline ll rd()
{
	static ll x,f;
	x=0;f=1ll;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1ll;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10ll+ch-'0';
	return f>0?x:-x;
}
const int N=50;
ll n,bin[N];
int m,a[N],t1=0,t2=0,s[N],t[N];

int main()
{
	bin[0]=1;fo(i,1,40)bin[i]=bin[i-1]<<1ll;
	n=rd();
	fo(i,0,40)if(n&bin[i])a[i]=1;
	int m=0;
	n++;
	while(n>1){
		if(n&1)s[++t1]=++m,n--;
		else t[++t2]=++m,n>>=1;
	}
	printf("%d\n",(t1+t2)<<1);
	fo(i,1,t1)cout<<101-s[i]<<' ';
	of(i,t2,1)cout<<101-t[i]<<' ';
	fo(i,101-t1-t2,100)cout<<i<<' ';cout<<endl;
	return 0;
}
