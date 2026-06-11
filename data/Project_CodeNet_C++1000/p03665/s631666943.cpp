#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N,P;
	cin>>N>>P;
	vector<int> A(N);
	rep(i,N) cin>>A[i];
	sort(A.begin(),A.end(),greater<int>());
	vector<ll> dp(N*100+1,0);
	dp[0]=1;
	for(int a : A)
	{
		for(int x=N*100;x>=a;x--)
		{
			dp[x]+=dp[x-a];
		}
	}
	ll ans=0;
	for(int i=P;i<=N*100;i+=2)
	{
		ans+=(ll)dp[i];
	}
	cout<<ans<<endl;
	return 0;
}
