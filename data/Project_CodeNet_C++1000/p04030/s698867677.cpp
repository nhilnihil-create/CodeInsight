#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;

int main()
{
    fast;
    
string s,ans="\0";
cin>>s;

ll cnt=0;
for(ll i=s.size()-1;i>=0;i--)
{
	
	if(s[i]=='B')cnt++;
	else if(cnt&&s[i]!='B')
	{
		cnt--;
		
	}
	else
	ans+=s[i];
}

reverse(ans.begin(),ans.end());
cout<<ans;
    
    
 
   
}

		
	
	
	
	
