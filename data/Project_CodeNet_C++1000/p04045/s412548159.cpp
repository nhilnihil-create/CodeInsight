#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 ll mod=1e9+7;

void test_case()
{
	set<ll>s={0,1,2,3,4,5,6,7,8,9};
	
	ll n,k;
	cin>>n>>k;
	ll a[k];
	for(int i=0;i<k;i++)
	{
		cin>>a[i];
		s.erase(a[i]);
	}
	ll ans=0,N=0;
	ll i=0,temp=n;
	
	while(n>0)
	{
		N=N*10+n%10;
		n=n/10;
	}
	
ll digit=0,yes=0;	
	while(N>0)
	{
		ll y=N%10;
		for(auto x:s)
	{
		//cout<<x<<" "<<y<<" "<<"\n";
		if(x>y)
		{
		ans=ans*10+x;
		yes=1;
		
		break;	
		}
		if(x==y)
		{
		
			ans=ans*10+x;
			
			
			break;
		}
		
		
		
	}
	N/=10;
	
	
	if(yes)break;
	
	
	}
	
	//cout<<ans<<" "<<yes<<"\n";
	if(yes||ans<temp)
	{
	//	cout<<ans<<" "<<temp<<"\n";
		while(ans<temp)
		{
			for(auto x: s)
			{
				ans=ans*10+x;
			//	cout<<ans<<"\n";
				break;
			}
		}
		
	}
	
	
	cout<<ans;
	
	
	
}

int main()
{
    fast;
    
//    ll t;
//    cin>>t;
//    while(t--)
    test_case();
    
    
 
   
}

		
	
	
	
	
