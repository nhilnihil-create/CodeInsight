#include<stdio.h>
#include<algorithm>
#define MAXN 100005
using namespace std;
template <typename T> inline void read(T &x)
{
	x=0;int f=1;char c=getchar();
	for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T> inline void print(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+48);
}
const int mod=1e9+7;
int t[MAXN],a[MAXN],n;
int mul(int x,int y) 
{
    return 1LL*x*y%mod;
}
int main() 
{
    read(n);
    for(int i=1;i<=n;++i) read(t[i]);
    for(int i=1;i<=n;++i) read(a[i]);
    int ans=1;
    for(int i=1;i<=n;++i) 
	{
	    if(t[i]!=t[i-1]||a[i]!=a[i + 1]) 
		{
	        int x=-1,y=-1;
	        if(t[i]!=t[i-1]) x=t[i];
	        if(a[i]!=a[i+1]) y=a[i];
	        if(x!=-1&&y!=-1) 
		        if(x!=y) 
		        {
		        	printf("0");
					return 0;
				}		
	        if(y>t[i]) 
			{
				printf("0");
				return 0;
			}
	        if(x>a[i]) 
			{
				printf("0");;
				return 0;
			}
	    }
	    else 
	        ans=mul(ans,min(a[i],t[i]));
    }
    print(ans);
    return 0;
}