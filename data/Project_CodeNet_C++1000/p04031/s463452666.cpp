#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;

int main()
{
    fast;
    
ll n;
cin>>n;
ll a[n];
for(auto &e:a)cin>>e;
ll cost=0,min_cost=inf;
for(ll i=-100;i<=100;i++)
{
	cost=0;
	for(auto x: a)
	{
		cost+=abs(x-i)*abs(x-i);
	}
	min_cost=min(min_cost,cost);
	
	
}
    
    cout<<min_cost;
    
 
   
}

		
	
	
	
	
