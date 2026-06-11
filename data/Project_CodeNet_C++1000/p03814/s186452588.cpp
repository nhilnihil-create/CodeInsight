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




string s;
cin>>s;
ll index1,index2;
for(ll i=0;i<s.size();i++)
{
	if(s[i]=='A')
	{
		index1=i;
		break;
	}
}
for(ll i=s.size()-1;i>=0;i--)
{
	if(s[i]=='Z')
	{
		index2=i;
		break;
	}
}

cout<<index2-index1+1;
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

		
	
	
	
	
