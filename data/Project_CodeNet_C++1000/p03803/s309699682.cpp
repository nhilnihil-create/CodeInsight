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

ll a,b;
cin>>a>>b;
if(a==1&&b!=1)cout<<"Alice";
else if(a!=1&&b==1)cout<<"Bob";
else if(a>b)
{
cout<<"Alice";	
}
else if(a<b)
{
	cout<<"Bob";
}
else
cout<<"Draw";
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

		
	
	
	
	
