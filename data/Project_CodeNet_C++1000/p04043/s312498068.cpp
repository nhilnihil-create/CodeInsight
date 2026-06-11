#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 ll mod=1e9+7;

void test_case()
{
	ll a,f=0,s=0;
	for(ll i=0;i<3;i++)
	{
		cin>>a;
		if(a==5)f++;
		if(a==7)s++;
	}
	if(f==2&&s==1)cout<<"YES";
	else
	cout<<"NO";
}

int main()
{
    fast;
    
//    ll t;
//    cin>>t;
//    while(t--)
    test_case();
    
    
 
   
}

		
	
	
	
	
