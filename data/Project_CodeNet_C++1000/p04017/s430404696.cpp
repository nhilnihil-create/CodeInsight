#include<bits/stdc++.h>
using namespace std;
int n;
int a[110000];
int L;
int k;
int f[110000][38];
int main() 
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    cin>>L>>k;
    for(int i=1;i<=n;i++)
    {
    	int sum=upper_bound(a+1,a+1+n,a[i]+L)-a-1;
    	if(a[i]+L>=a[n])
    	{
    		f[i][0]=n;
    	}
    	else 
    	{
    		f[i][0]=sum;
    	}
    }
	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
//    for(int i=1;i<=k;i++)
//    {
//    	cin>>x>>y;
//    }
	while(k--)
	{
		int x;
		int y;
		cin>>x>>y;
		if(y<x)
		swap(x,y);
		long long ans=0;
        for(int i=30;i>=0;i--)
        {
            if(f[x][i]<y)
            {
                ans+=1ll<<i;
                x=f[x][i];
            }
        }
        printf("%lld\n",ans+1);
	}
    return 0;
}