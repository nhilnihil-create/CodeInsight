#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
string a,b,c;


 void test_cases()
{


ll k,s;
cin>>k>>s;
ll sum=0,z=0,cnt=0;

for(ll x=0;x<=min(s,k);x++)
{
	for(ll y=0;y<=min(s,k);y++)
	{
		sum=x+y;
		z=s-sum;
		if(z>=0&&z<=k)
		cnt++;
	}
}


cout<<cnt;
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

		
	
	
	
	
