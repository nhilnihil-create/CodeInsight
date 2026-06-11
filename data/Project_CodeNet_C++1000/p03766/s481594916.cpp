#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int ha=1e9+7;
int n;
int f[2000005];
int sum;
int main()
{
	scanf("%d",&n);
	f[n]=n;
	for(int i=n+1;i<=2*n;i++) f[i]=1;
	for(int i=n+2;i<=2*n;i++) sum+=f[i];
	for(int i=n-1;i>=1;i--)
	{
		f[i]=(f[i+1]+1ll*(n-1)*(n-1)%ha+sum)%ha;
		sum-=f[i+n+1];
		sum=(sum+f[i+2])%ha;
	}
	printf("%d\n",f[1]);
	return 0;
}
//f[i]=f[i+1]+(n-1)^2+f[i+3]+...+f[i+n+1](i<n)
//f[i]=f[i+1]+f[i+3]+...+f[i+n+1]=n(i==n)
//f[i]=1(i>n)
/*#include<iostream>//dfs(30points)
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ha 1000000007
int n,ans;
int f[1000005];
int dfs(int p)
{
	if(p>n) return 1;
	int ans=0;
	if(f[p]) return f[p];
	else
	{
		ans=(ans+dfs(p+1))%ha;
		for(int i=2;i<=n;i++)
		{
			if(p<n) ans=(ans+n-1)%ha;
			ans=(ans+dfs(p+i+1))%ha;
		}
	}
	return f[p]=ans;
}
int main()
{
	scanf("%d",&n);
	ans=dfs(1);
	printf("%d\n",ans);
	return 0;
}*/