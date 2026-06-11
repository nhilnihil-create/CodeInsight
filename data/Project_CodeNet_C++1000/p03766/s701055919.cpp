# include<iostream>
# include<cstring>
# include<cstdio>
# include<algorithm>
using namespace std;
const int MAX=1e6+5,mod=1e9+7;
int n;
int f[MAX];
int main()
{
	scanf("%d",&n),f[n]=n,f[n-1]=1ll*n*n%mod;
	for(int i=n-2,sum=0;i>=1;--i)
	  (sum+=f[i+3])%=mod,(f[i]+=((1ll*(n-1)*(n-1)%mod+f[i+1])%mod+i+1+sum)%mod)%=mod;
	return printf("%d",f[1]),0;
}