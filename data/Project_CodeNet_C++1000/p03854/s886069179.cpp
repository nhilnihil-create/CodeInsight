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
	ll n=s.size();
	
	string dream,erase;
	dream="dream";
	erase="erase";
	ll ok=0;
	for(ll i=0;i<n;)	
	{
		if(s.substr(i,5)==dream||s.substr(i,5)==erase)
		{
			if(s.substr(i,6)=="eraser")
			{
				i+=6;
			}
			else
			i+=5,ok=1;
			
			
		}
		else
		{
			if(s.substr(i,2)=="er" &&ok)
			{
				i+=2;
				ok=0;
			}
			else
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	
	
	cout<<"YES";
	
	
}



		
	
	
	
	
