#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
void seive(vector<int> &v,int n)
{
	for(int i=1;i<=n;i++)
		v[i]=i;
	for(int i=2;i<=n;i+=2)
		v[i]=2;
	for(int i=3;i*i<=n;i++)
	{
		if(v[i]==i)
		{
			for(int j=i;j<=n;j+=i)
				if(v[j]==j)
					v[j]=i;
		}
	}
}

int main(){
	fast;
	ll n;
	cin>>n;
	vector<int> v(n+1,1);
	ll arr[n+1]{};
	ll ans=1;
	seive(v,n);
	for(int i=2;i<=n;i++)
	{
		int x=i;
		while(x!=1)
		{
			arr[v[x]]++;
			x=x/v[x];
		}
	}
	for(int i=1;i<=n;i++)
		if(arr[i]>=1)
			ans=(ans*(arr[i]+1))%MOD;
	cout<<ans;
	return 0;
}

