#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1e9+7;

void solve()
{
	ll sx,sy,tx,ty;
	ll y,x;
	cin>>sx>>sy>>tx>>ty;
	y=ty-sy;
	x = tx-sx;
	for(ll i=0;i<y;i++)
    	cout<<"U";

	  for(ll i=0;i<x;i++)
	    cout<<"R";
	  
	  for(ll i=0;i<y;i++)
	    cout<<"D";
	
	  for(ll i=0;i<x;i++)
	    cout<<"L";
	    
	  cout<<"L";
	  for(ll i=0;i<y+1;i++)
	    cout<<"U";
	  
	  for(ll i=0;i<x+1;i++)
	    cout<<"R";
	
	  cout<<"D";
	  cout<<"R";
	  for(ll i=0;i<y+1;i++)
	    cout<<"D";
	  
	  for(ll i=0;i<x+1;i++)
	    cout<<"L";
	
	  cout<<"U";
	return;
}
int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}