#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;

int main()
{
    fast;

	
	string s;
	cin>>s;
	ll n;
	for(ll i=1;i<s.size()-1;i++)
	{
			
			if( (s[i]!=s[0]||s[i]!=s[s.size()-1] ))
			{
				
				n=s.size()-2;
				break;		
			}
			
	}
 
 if(s[0]!=s[s.size()-1])
 {
 	if(n%2==0)cout<<"Second";
 	else
 	cout<<"First";
 }
 else
 {
 	if(n%2==0)cout<<"First";
 	else
 	cout<<"Second";
 }
    
   
}

		
	
	
	
	
