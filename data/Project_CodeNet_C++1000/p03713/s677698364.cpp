#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll h,w;
	cin>>h>>w;
	ll a=0,b=0,c=0,mind=h*w,M,m;
	for(ll i=1;i<=h-1;i++)
	{
		b = ((h-i)/2)*w;
		c = ((h-i+1)/2)*w;
		a = i*w;
		M = max(a,max(b,c));
		m = min(a,min(b,c));
		if(M-m<mind)
			mind = M-m;
		b = (h-i)*(w/2);
		c = (h-i)*((w+1)/2);
		a = i*w;
		M = max(a,max(b,c));
		m = min(a,min(b,c));
		if(M-m<mind)
			mind = M-m;

	}

	for(ll i=1;i<=w-1;i++)
	{
		b = ((w-i)/2)*h;
		c = ((w-i+1)/2)*h;
		a = i*h;
		M = max(a,max(b,c));
		m = min(a,min(b,c));
		if(M-m<mind)
			mind = M-m;		
		b = (w-i)*(h/2);
		c = (w-i)*((h+1)/2);
		a = i*h;
		M = max(a,max(b,c));
		m = min(a,min(b,c));
		if(M-m<mind)
			mind = M-m;
	}
	cout<<mind<<"\n";
}
	
	
