#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;

int main()
{
    fast;
    
 ll n,k,x,y;
 cin>>n>>k>>x>>y;
 
 ll ans;
 
 ans=min(k,n)*x+(max(n-k,0LL) )*y;
 
 cout<<ans;
    
   
}

		
	
	
	
	
