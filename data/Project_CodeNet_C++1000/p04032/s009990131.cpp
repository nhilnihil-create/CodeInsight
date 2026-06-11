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

map<char,vector<ll>>m;

for(ll i=0;i<s.size();i++)
{
	m[s[i]].push_back(i);
}
ll a,b;
bool ok=false;
for(auto x:m )
{
//	cout<<x.second.size()<<" \n";
	for(ll i=x.second.size()-1;i>=0;i--)
	{
		
		for(ll j=0;j<i;j++)
		{
			
		//	cout<<x.second[i]<<" "<<x.second[j]<<"....\n";
			if((x.second[i]-x.second[j]+1)/2<i-j+1)
			{
				ok=true;
				a=x.second[j]+1;
				b=x.second[i]+1;
				break;
			}
			
		}
		if(ok)break;
		
		}
		if(ok)break;	
		
	
	
}

if(ok)cout<<a<<" "<<b;
else
cout<<-1<<" "<<-1;
    
 
   
}

		
	
	
	
	
