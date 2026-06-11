#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5;
int n;
int a[maxn*2+8],b[maxn*2+8];

int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

bool check(int k)
{
    for (int i=1;i<2*n;i++) b[i]=a[i]>=k;
    for (int i=1;i<n;i++)
	{
	    if ((b[n-i]&&b[n-i+1])||(b[n+i]&&b[n+i-1])) return 1;
	    if ((!(b[n-i]||b[n-i+1]))||(!(b[n+i]||b[n+i-1]))) return 0;
	}
    return b[1];
}

int main()
{
    n=read();
    for (int i=1;i<2*n;i++) a[i]=read();
    int l=1,r=2*n-1,ans;
    while(l<=r)
	{
	    int mid=(l+r)>>1;
	    if (check(mid)) l=mid+1,ans=mid;
	    else r=mid-1;
	}
    printf("%d\n",ans);
    return 0;
}
