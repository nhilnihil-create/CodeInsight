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
sort(s.begin(),s.end());
s+='0';
for(ll i=0;i<s.size()-1;i+=2)
 {
 	if(s[i]!=s[i+1])
 	{
 		cout<<"No";
 		exit(0);
	 }
 }
 
 cout<<"Yes";
    
   
}

		
	
	
	
	
