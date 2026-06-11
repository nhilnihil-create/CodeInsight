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


ll sx,sy,tx,ty;
cin>>sx>>sy>>tx>>ty;


	for(ll i=0;i<abs(sx-tx);i++)cout<<"R";
	for(ll i=0;i<abs(sy-ty)+1;i++)cout<<"U";
	for(ll i=0;i<abs(sx-tx)+1;i++)cout<<"L";
	for(ll i=0;i<abs(sy-ty)+1;i++)cout<<"D";
	cout<<"R";
		for(ll i=0;i<abs(sy-ty);i++)cout<<"U";
	for(ll i=0;i<abs(sx-tx)+1;i++)cout<<"R";
	for(ll i=0;i<abs(sy-ty)+1;i++)cout<<"D";
	for(ll i=0;i<abs(sx-tx)+1;i++)cout<<"L";

	cout<<"U";	

 
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

		
	
	
	
	
