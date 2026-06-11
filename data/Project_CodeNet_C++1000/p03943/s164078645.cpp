#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int d=0;
	d=max(a,max(b,c));
	if(d==a+b)
	cout<<"Yes"<<endl;
	else if(d==b+c)
	cout<<"Yes"<<endl;
		else if(d==a+c)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	return 0;
}