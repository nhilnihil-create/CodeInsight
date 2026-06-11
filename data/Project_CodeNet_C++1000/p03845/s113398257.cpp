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
 vector<ll>t(n);
 ll tot=0;
 for(auto &e:t)cin>>e,tot+=e;
 
 ll m;
 cin>>m;
 
 for(ll i=0;i<m;i++)
 {
 	ll new_tot=tot;
 	ll p,x;
 	cin>>p>>x;
 	new_tot+=x-t[p-1];
 	
 	cout<<new_tot<<"\n";
 
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

		
	
	
	
	
