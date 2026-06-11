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
 ll a=0,b=0;
 for(ll i=0,x,y;i<n;i++)
 {
 	cin>>x>>y;
 	
 	
 	if(i==0)
 	{
 		a=x,b=y;
 		continue;
	 }
	
	
	ll x1,y1;
	x1=ceil((long double)a/(long double)x);
	y1=ceil((long double)b/(long double)y);
	
	ll curl=max(x1,y1);

	//cout<<curl<<"\n";
	a=x*curl;
	b=y*curl;
 	
 }
 
 
 
 cout<<a+b;
    
   
}

		
	
	
	
	
