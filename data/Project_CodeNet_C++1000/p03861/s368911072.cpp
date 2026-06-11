#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
string a,b,c;

queue<char>q[3];


int main()
{
    fast;
  
  ll a,b,x;
  cin>>a>>b>>x;
  
  ll ans;
  
  ans=b/x;
  ans=ans-(a/x);
  
  if(a%x==0)ans++;
  cout<<ans;
  	
}

		
	
	
	
	
