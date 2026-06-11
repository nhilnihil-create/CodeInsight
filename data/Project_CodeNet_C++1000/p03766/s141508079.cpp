#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int Mod = 1000000007;
int n,m,f[N],ans;
int main()
{
	cin>>n;
	m=(1ll*(n-1)*(n-1))%Mod;
	if(n>2) ans=m+2;
	else ans=m+1;
	int sum=f[0]=1;
	for(int i=1;i<n;i++)
	{
		f[i]=sum;
		if(i-2>=0) f[i]=(f[i]-f[i-2]+Mod)%Mod;
		sum=(sum+f[i])%Mod;
		if(i!=n-1) ans=(ans+1ll*f[i]*(m+min(i+2,n-1))%Mod)%Mod;
        else ans=(ans+1ll*f[i]*n%Mod)%Mod;
	}
	cout<<ans<<"\n";
}