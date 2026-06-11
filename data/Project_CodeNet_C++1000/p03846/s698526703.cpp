#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
void solve()
{
	ll n,i,ans=1;
	cin>>n;
	ll a[n];
	map<int,int> m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	for(auto it:m)
	{
		if(it.first==0 && it.second!=1)
			{
				ans=0;
				break;
			}
			else if(it.first==0)
			{
				continue;
			}
			else if(it.second!=2)
			{
				ans=0;
				break;
			}
			else
			{
				ans=ans*2;
				ans=ans%MOD;
			}
	}
	cout<<ans<<endl;

}
	
int main()
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output1.txt", "w", stdout);
//#endif
	ll t=1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
}