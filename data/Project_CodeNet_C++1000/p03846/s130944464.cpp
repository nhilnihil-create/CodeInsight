#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

void power(ll a, ll b)
{
	ll ans = 1;
	while(b)
	{
		if(b&1)
			ans = ans* a %mod;
		a = a*a%mod;
		b = b>>1;
	}
	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a,b[n];
	memset(b,0,sizeof(b));
	for(int i = 0;i<n; i++)
	{
		cin>>a;
		b[a]++;
	}
	int coun= 0,i=1;
	if(n&1)
		for(i=0;i <n; i+=2)
		{
			if(i==0 && b[i]==1)
				continue;
			else if(b[i]!=2)
			{
				cout<<0<<endl;
				return 0;
			}
		}
	else
	{
		for(i = 1; i<n; i+=2)
			if(b[i]!=2)
			{
				cout<<0<<endl;
				return 0;
			}
	}
	power(2,n/2);
	return 0;
}