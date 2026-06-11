#include<bits/stdc++.h>
using namespace std;
int n,k;
long long f[2005][2005],fac[4000005],inv_fac[4000005];
inline long long C(int n,int m)
{ 
	return (((fac[m]*inv_fac[n])%1000000007)*inv_fac[m-n])%1000000007; 
}
long long power(long long x,int p)
{
    long long ans=1,m=x;
    while(p)
	{
        if(p%2==1) 
		{
        	ans*=m;
			ans%=1000000007;
		}
		p/=2;
		m*=m;
		m%=1000000007;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&k);
    if(k==1)
	{ 
		printf("%d\n",1); 
		return 0; 
	}
    fac[0]=1; 
	for(register int i=1;i<=4000005;i++) 
		fac[i]=(fac[i-1]*i)%1000000007;
    inv_fac[4000005]=power(fac[4000005],1000000005); 
	for(register int i=4000004;i>=0;i--) 
		inv_fac[i]=(inv_fac[i+1]*(i+1))%1000000007;
    f[0][0]=1;
    for(register int i=1;i<=n;i++)
	{
        for(register int j=0;j<=i;j++)
		{
            f[i][j]=f[i-1][j];
            if(!j) 
				continue;
            (f[i][j]+=f[i][j-1]*(n-j+1)%1000000007*C(k-2,n-i+(n-j+1)*(k-1)-1)%1000000007)%=1000000007;
        }
    }
    printf("%lld\n",f[n][n]);
    return 0;
}