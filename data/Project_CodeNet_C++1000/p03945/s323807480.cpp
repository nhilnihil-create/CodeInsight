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
	ll cnt1=0,cnt2=0;
	for(ll i=0,j=s.size()-1;i<s.size()-1;i++,j--)
	{
		
		if(s[i]!=s[i+1])cnt1++;
		
		if(s[j]!=s[j-1])cnt2++;
	}
   
   
   cout<<min(cnt1,cnt2);
}

		
	
	
	
	
