#include<iostream>
using namespace std;
long mod=1e9+7,p2[5005],F[2][5005],G[2][5005],T[5005];
int N,M;
string s;
main()
{
	cin>>N>>s;
	M=s.size();
	long ans=0;
	p2[0]=1;
	for(int i=1;i<=5000;i++)p2[i]=p2[i-1]*2%mod;
	G[0][0]=1;
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=5000;j++)G[1-i%2][j]=0;
		for(int j=0;j<=5000;j++)
		{
			(G[1-i%2][j+1]+=G[i%2][j])%=mod;
			if(j>1)(G[1-i%2][j-1]+=G[i%2][j])%=mod;
		}
		if(i>=M)T[i-M]=G[i%2][M];
	}
	F[0][0]=1;
	for(int i=0;i<=N-M;i++)
	{
		for(int j=0;j<=5000;j++)F[1-i%2][j]=0;
		for(int j=0;j<=5000;j++)
		{
			(F[1-i%2][j+1]+=F[i%2][j]*2)%=mod;
			(F[1-i%2][j>0?j-1:0]+=F[i%2][j])%=mod;
		}
		if((N-M-i)%2!=0)continue;
		int t=(N-M-i)/2;
		long now=F[i%2][0]*p2[t]%mod*T[t*2]%mod;
		(ans+=now)%=mod;
	}
	cout<<ans<<endl;
}