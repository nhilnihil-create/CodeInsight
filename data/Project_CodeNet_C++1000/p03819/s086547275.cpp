#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;int n,m,li,ri,l,r;
LL s[100010];
inline LL read()
{
	char c;LL d=1,f=0;
	while(c=getchar(),!isdigit(c)) if(c=='-') d=-1;f=(f<<3)+(f<<1)+c-48;
	while(c=getchar(),isdigit(c)) f=(f<<3)+(f<<1)+c-48;
	return d*f;
}
signed main()
{
	n=read();m=read();
	for(register int i=1;i<=n;i++)
	{
		li=read();ri=read();
		s[li]++;s[ri+1]--;
		li--;
		for(l=1;l<=li;l=r+1)
		{
			r=min(li/(li/l),ri/(ri/l));
			if(li/l!=ri/l) s[l]++,s[r+1]--;
		}
	}
	for(register int i=1;i<=m;i++)
	{
		s[i]+=s[i-1];
		printf("%lld\n",s[i]);
	}
}