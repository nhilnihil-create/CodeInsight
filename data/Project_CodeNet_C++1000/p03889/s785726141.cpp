#include<string>
#include<iostream>
using namespace std;
int main()
{
	int i,m;
	string a,b;
	cin>>a;
	m=-1;
	b="";
	for(i=a.size()-1;i>=0;i--)
	{
		m++;
		if(a[i]=='p')
			b=b+'q';
		if(a[i]=='q')
			b=b+'p';
		if(a[i]=='b')
			b=b+'d';
		if(a[i]=='d')
			b=b+'b';
	}
	if(a==b)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}