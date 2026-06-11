#include  <bits/stdc++.h>
using namespace std;
int main()
{
	int i,h,w;
	cin>>h>>w;
	string a[h];
	for(i=0;i<h;i++)
	{
		cin>>a[i];
		a[i]='#'+a[i]+'#';	
	}	
	
	for(i=0;i<w+2;i++)
	{
		cout<<'#';
	}
	cout<<endl;
	for(i=0;i<h;i++)
	{
		cout<<a[i]<<endl;
	}
	for(i=0;i<w+2;i++)
	{
		cout<<'#';
	}
	
	
}