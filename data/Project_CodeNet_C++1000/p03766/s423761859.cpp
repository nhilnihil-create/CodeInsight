#include<iostream>
#include<algorithm>
using namespace std;
long mod=1e9+7,N;
long cumsum[1<<20];
long c2[1<<20];
main()
{
	cin>>N;
	long ans=0;
	cumsum[0]=1;
	for(int i=0;i<N;i++)
	{
		long t=(cumsum[i]+c2[i])%mod;
		(c2[i+3]+=t)%=mod;
		if(i+1<N)(ans+=t*(N-1)%mod*(N-1)%mod+t*(N-max(N-i-1,2L)+1)%mod)%=mod;
		else(ans+=t*N)%=mod;
		(c2[i+1]+=c2[i])%=mod;
		(cumsum[i+1]+=t)%=mod;
	}
	cout<<ans<<endl;
}