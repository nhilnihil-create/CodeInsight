#include<stdio.h>
#include<algorithm>
#define MAXN 100005
using namespace std;
const int mod=1e9+7;
int t[MAXN],a[MAXN],n;
int mul(int x,int y) 
{
    return 1LL * x * y % mod;
}
int main() 
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&t[i]);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
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
    printf("%d",ans);
    return 0;
}