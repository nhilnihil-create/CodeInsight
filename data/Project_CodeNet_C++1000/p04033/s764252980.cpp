#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,i,x=0;
	cin>>a>>b;
	if(a<=0 && b>=0)
		{
			cout<<"Zero"<<endl;
			return 0;
		}
	for(i=a;i<=b;i++)
	{
		if(i<0)
		{
			x++;
		}
	}
	if(x%2!=0)
	{
		cout<<"Negative"<<endl;
	}
	else
	{
		cout<<"Positive"<<endl; 
	}
}