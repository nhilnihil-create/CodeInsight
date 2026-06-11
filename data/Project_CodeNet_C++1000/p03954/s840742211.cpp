#include <bits/stdc++.h>
#define res register int
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define INF 1000000007
#define gc getchar()
#define MAXN 1000005
#define lc pos<<1
#define rc pos<<1|1
using namespace std;

inline int read()
{
    int ch=gc,f=0;
    int x=0;
    while(ch<'0'||ch>'9')
    {
        f|=ch=='-';
        ch=gc;
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=gc;
    }
    return f?-x:x;
}
int n,m;
int a[MAXN],f[MAXN];
inline bool check(int lim)
{
	for(int i=1;i<=2*n+1;i++)
	f[i]=a[i]<=lim;
	for(int i=0;i<n;i++)
	{
		if(f[n+1+i]==f[n+2+i])
		return f[n+1+i];
		if(f[n+1-i]==f[n-i])
		return f[n-i];
	}
	return f[1];
}
int main()
{
	n=read()-1;
	for(int i=1;i<=2*n+1;i++)
	a[i]=read();
	int l=1,r=2*n+1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))
		r=mid;
		else
		l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}