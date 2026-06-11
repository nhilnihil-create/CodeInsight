#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
string a,b,c;

ll mod(ll a)
{
	if(a<inf)return a;
	else 
	return a%inf;
}
 void test_cases()
{


ll n;
cin>>n;

vector<ll>a(n);

map<ll,ll>m;
for(auto &e:a)cin>>e,m[e]++;
ll ans=1;
for(auto x:m)
{
	if(n%2==0)
	{
		if(x.first==0)
		{
			cout<<0;
			return;
		}
	}
	if(x.first%2!=n%2)
	{	
		if(x.first==0)continue;
		if(x.second!=2)
		{
			cout<<0;
			return;
		}
		else
		{
			ans=ans*2;
			ans=mod(ans);
		}
	}
	else
	{
		cout<<0;
		return;
	}
}

cout<<ans;



	

 
}


int main()
{
    fast;
  ll t;
 // cin>>t;
 t=1;
  while(t--)
  test_cases();

  	
}

		
	
	
	
	
