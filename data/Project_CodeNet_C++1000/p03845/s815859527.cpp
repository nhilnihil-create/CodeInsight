#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll n,m,val,index,sum;
	cin>>n;
	ll arr[n+1];
	for(ll i=1;i<=n;i++)
		cin>>arr[i];
	cin>>m;
	while(m--)
	{
		sum=0;
		cin>>index>>val;
		for(int i=1;i<=n;i++)
		{
			if(index==i)
				sum+=val;
			else
				sum+=arr[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
