#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
char S[8];
int ans,len;

int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

void query(ll x)
{
    printf("? %lld\n",x);
    fflush(stdout);
    scanf("%s",S);
}

int main()
{
    int x=1000000000;
    query(x);
    if (S[0]=='Y')
	{
	    for (int i=8;~i;i--)
		{
		    query(x-1);
		    if (S[0]=='N') break;
		    x/=10;
		}
	    printf("! %d\n",x);
	    return 0;
	}
    for (int i=8;~i;i--)
    	{
	    x/=10;
	    query(x);
	    if (S[0]=='Y')
		{
		    len=i+1;
		    break;
		}
	}
    int l=x+1,r=x*10-1;
    while(l<=r)
	{
	    ll mid=(l+r)>>1;
	    query(mid*10);
	    if (S[0]=='Y') ans=mid,r=mid-1;
	    else l=mid+1;
	}
    printf("! %d\n",ans);
    return 0;
}
	    
