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
s+='0';
ll ans=0,g=0,p=0;
for(ll i=0;i<s.size();i++)
{
	if(s[i]=='g')g++;
	else 
	{
		
		if(s[i]=='p')
		p++;
		//if(p==g)g=0,p=0;
		if(g-p>=2)
		{
			ll x=(g-p)/2;
			
			g-=x;
			p+=x;
			
			ans+=x;
		}
		if(p>g)
		{
			p--;
			g++;
			ans--;
		}
		
	}
	
//	cout<<g<<" "<<p<<" "<<ans<<"\n";
	
	
	
}

cout<<ans;



 
    
   
}

		
	
	
	
	
