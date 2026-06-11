#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n,b=0,x=0,y=0,z=0,u=0,v=0,w=0,g=0,h=0,min,max;
	cin>>n;
	long int i,a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
				
				
				if(a[i]>=1 && a[i]<=399)
				{
					x=1;
				}
				if(a[i]>=400 && a[i]<=799)
				{
					y=1;
				}
				if(a[i]>=800 && a[i]<=1199)
				{
					z=1;
				}
				if(a[i]>=1200 && a[i]<=1599)
				{
					u=1;
				}
				if(a[i]>=1600 && a[i]<=1999)
				{
					v=1;
				}
				if(a[i]>=2000 && a[i]<=2399)
				{
					w=1;
				}if(a[i]>=2400 && a[i]<=2799)
				{
					g=1;
				}
				if(a[i]>=2800 && a[i]<=3199)
				{
					h=1;
				}
				if(a[i]>3199)
				{
					b++;
				}
	}
	
	min=x+y+z+u+v+w+g+h;
	max=min+b;
	if(min==0)
	{
		min=1;
	}

	cout<<min<<" "<<max<<endl;
	
}