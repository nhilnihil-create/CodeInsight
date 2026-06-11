#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
string a,b,c;


 void test_cases()
{

ll n;
cin>>n;
string s;
cin>>s;
ll ans=0,x=0;
for(ll i=0;i<n;i++)
{
	if(s[i]=='I')x++;
	else
	x--;
	
	ans=max(ans,x);
}

cout<<ans;
}


int main()
{
    fast;
  ll t;
 // cin>>t;
 t=1;
  while(t--)
  test_cases();

  	
}

		
	
	
	
	
