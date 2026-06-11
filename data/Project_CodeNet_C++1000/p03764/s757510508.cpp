#include <iostream>
using namespace std;
#define mod 1000000007
#define ll long long
long long solve(int n)
{ll sum=0;ll ans=0;
for(ll i=1;i<=n;i++){
   ll x;cin>>x;
   sum+=x;
   ans=(ans+(i*x-sum))%mod;
   
}
return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	long long x=solve(n),y=solve(m);
	printf("%lld",(x*y)%mod);
}