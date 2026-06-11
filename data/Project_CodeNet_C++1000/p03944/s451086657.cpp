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
  
  ll w,h,n;
  cin>>w>>h>>n;
  
  ll x,y,a,x1=0,y1=0;
  
  for(ll i=0;i<n;i++)
  {
  	
  	cin>>x>>y>>a;
  	
  	ll x3=x;
  	ll y3=y;
  	x=x-x1;
  	y=y-y1;
  	if(a==1)
  	{
  		if(x>=0)
  	{
  			w-=x;
  		x1=x3;
	  }
  		
	  }
  	if(a==2)
  	{
  		if(x<=w)
		  w=x;
  		
  		
  		
	  }
  	if(a==3)
  	{
  		if(y>=0){
  				h-=y;
  		y1=y3;
		  }
  	
	  }
  	if(a==4)
  	{
  		if(y<=h)
  		h=y;
  		
	  
	  }
	  
	 // cout<<w<<" "<<h<<"\n";
  	
  }
  w=max(w,0LL);
  h=max(h,0LL);
  cout<<w*h;
}

		
	
	
	
	
