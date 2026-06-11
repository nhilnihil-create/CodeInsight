#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main()
{
	ll n,t,a[200005],sum=0;
	cin>>n>>t;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		if(i)
		{
			if(a[i-1]+t<a[i])sum+=t;
			else sum+=a[i]-a[i-1];
		}
	}
	cout<<sum+t<<endl;
	return 0;
}
