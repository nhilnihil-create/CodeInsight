#include<bits/stdc++.h>
#define MAXN ((int)(1e5+10))
#define INF ((int)(1e9))
using namespace std;
typedef long long LL;
int n,k;
LL a[MAXN],sum=0,ans=-INF,tmp=0;
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		tmp+=a[i];
		if(a[i]>0)
			sum+=a[i];
	}
	LL integer=0,fu=0;
	for(int i=0;i<k;i++)
	{
		if(a[i]>0)
			integer+=a[i];
		else
			fu+=(0-a[i]);
	}
	for(int i=0;i<=n-k;i++)
	{
		LL rec;
		if(integer>=fu)
			rec=sum-fu;
		else
			rec=sum-integer;
		ans=max(ans,rec);
		if(a[i]>0)
			integer-=a[i];
		else
			fu-=(0-a[i]);
		if(a[i+k]>0)
			integer+=a[i+k];
		else
			fu+=(0-a[i+k]);
	}
	cout<<ans<<endl;
	return 0;
} 