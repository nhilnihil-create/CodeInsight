#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int ans=0;
	
	while(1)
	{
		 if(a%2!=0 || b%2!=0 || c%2!=0)
		{
			break;
		}
		if(a==b && b==c && a==c)
		{
		ans=-1;
		break;
		}
		
		int a1 = b+c;
		int b1 = a+c;
		int c1 = a+b;
		
			ans++;		
			
			a=a1/2;
			b=b1/2;
			c=c1/2;			
	}
	cout<<ans;	
}
