#include<iostream>
#include<algorithm>
using lint=int64_t;
using namespace std;

int main()
{
	int N,K;
	lint a[100010]={};

	cin >> N >> K;
	for(int i=1;i<=N;i++)
		cin >> a[i];

	lint sum[100010]={};
	lint sump[100010]={};
	for(int i=1;i<=N;i++)
	{
		sum[i]=sum[i-1]+a[i];
		sump[i]=sump[i-1];
		if(a[i]>0)
			sump[i]+=a[i];
	}

	lint ans=0;
	for(int l=1;l<=N-K+1;l++)
	{
		int r=l+K-1;
		lint tans=sump[l-1]+max((lint)0,sum[r]-sum[l-1])+(sump[N]-sump[r]);
		ans=max(ans,tans);
	}

	cout << ans << endl;
	return 0;
}
