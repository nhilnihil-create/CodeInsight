#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c1=0,c2=0;
	int a[3];
	for(int i=0;i<3;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<3;i++)
	{
		if(a[i]==5)
		{
			c1++;
		}
		else if(a[i]==7)
		{
			c2++;
		}
	}
	if(c1==2 && c2==1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	
	
	

	
}