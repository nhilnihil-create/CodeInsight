#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


bool ok(vector<ll>&h,ll mid,ll a,ll b)
{
	int i,n=h.size();
	ll t=0LL;
	for(i=0;i<n;i++)
	{
		ll ans = h[i]-b*mid;
		if(ans>0LL)
		{
			t+=ceil(ans*1.0/(a-b));
		}
	}
	if(t<=mid)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(){
	int n,i;
	ll a,b;
	cin>>n;
	cin>>a>>b;
	vector<ll> h(n);
	for(i=0;i<n;i++)
	{
		cin>>h[i];
	}
	ll low,high,mid;
	low=0LL;
	high=1000000000LL;
	ll ans = -1LL;
	while(low<=high)
	{
		mid = low+(high-low)/2LL;
		if(ok(h,mid,a,b))
		{
			high=mid-1LL;
			ans = mid;
		}
		else
		{
			low=mid+1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}