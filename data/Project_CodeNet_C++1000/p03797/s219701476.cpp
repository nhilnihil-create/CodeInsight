#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
string a,b,c;

ll mod(ll a)
{
	if(a<inf)return a;
	else 
	return a%inf;
}
 void test_cases()
{

ll s,c;
cin>>s>>c;

	
if(c>=2*s)
{
	c-=2*s;
	
	if(c)
	{
		c=c/4;
	}
	cout<<s+c;
	}
	else
	{
		c=c/2;
		s=min(s,c);
		cout<<s;
		}	





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

		
	
	
	
	
