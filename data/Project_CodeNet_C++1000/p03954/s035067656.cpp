#include<bits/stdc++.h>
using namespace std;
#define RI register int
#define LL long long
inline int read()
{
    int res=0,f=1;
    char ch=getchar();
    while(ch!='-'&&(ch>'9'||ch<'0'))
        ch=getchar();
    if(ch=='-')
        f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')
        res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
    return res*f;
}
const int N=2e5+5;
int n,a[N],b[N];
bool check(int mid)
{
	for(RI i=1;i<2*n;++i)
		b[i]=1;
	for(RI i=1;i<2*n;++i)
	{
		if(a[i]>mid)
			b[i]=0;
	}
	bool flag=1;
	for(RI i=2;i<2*n;++i)
		if(b[i]==b[i-1])
			flag=0;
	/*printf("%d\n",mid);
	for(RI i=1;i<2*n;++i)
		printf("%d ",b[i]);
		printf("\n\n");*/
	if(flag)
		return b[1];
	int l=n,r=n;
	while(b[l]!=b[l-1]&&b[r]!=b[r+1])
	{
		l--,r++;
	}
	if(b[l]==b[l-1])
		return b[l];
	return b[r];
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	int l=0,r=0,ans=0;
	for(RI i=1;i<2*n;++i)
	{
		a[i]=read();
		r=max(r,a[i]);
	}
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
