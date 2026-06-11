#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ini(a,i) memset(a,i,sizeof(a))
#define pb push_back
#define ll long long
#define inf LLONG_MAX

void solve()
{
	ll n,k,i;
	cin>>n>>k;

	ll hash=0;
	for(i=0;i<k;i++)	
	{
		ll val;
		cin>>val;

		hash|=(1LL << val);
	}

	while(1)
	{
		ll val=0;

		for(i=n;i>0;i/=10)	
		{
			val|=(1LL<<(i%10));
		}
		
		if((val & hash )== 0)
		{
			cout<<n<<endl;
			return;
		}
		n++;
	}
	
}


int main()
{
	std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//ll tt;	cin>>tt;	while(tt--)
	{
		solve();
 	}
	cerr<<" Execution : "<<(1.0*clock())/CLOCKS_PER_SEC<<"s \n";
		
		
return 0;
}