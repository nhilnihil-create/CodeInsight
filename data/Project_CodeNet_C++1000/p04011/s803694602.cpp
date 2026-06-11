#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,sum=0;
	cin>>a>>b>>c>>d;
	for(int i=0;i<a;i++)
	{
		if(i<b) sum+=c;
		else sum+=d;
	}
	cout<<sum;
}