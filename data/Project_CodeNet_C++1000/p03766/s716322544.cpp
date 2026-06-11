#include<bits/stdc++.h>
#define N 1000005
#define LL long long
using namespace std;
const int mo=1e9+7;
int n; LL f[N],S,ans;
LL G(int t,int n)
{
	return (1LL*(t+1)*n+1LL*(n-t-2)*(n-1))%mo;
}
int main()
{
	int i;
	cin>>n;
	if(n==1){ printf("1"); return 0;}
	f[0]=S=1,ans=G(0,n);
	for(i=1;i<=n;i++){
		f[i]=S;
		if(i>1) f[i]=(f[i]+mo-f[i-2])%mo;
		if(i<n-1) ans=(ans+f[i]*G(i,n))%mo;
		else if(i==n-1) ans=(ans+f[i]*(n-1))%mo;
		else ans=(ans+f[i])%mo;
		S=(S+f[i])%mo;
	  }
	cout<<ans;
	return 0;
}
