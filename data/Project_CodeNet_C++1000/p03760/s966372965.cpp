#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long 
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	int n=a.length()+b.length();
	char name[n+2];
	int i=1;
	for(int j=0;j<a.length();j++)
	{
		name[i]=a[j];
		i+=2;
	}
	i=2;
	for(int j=0;j<b.length();j++)
	{
		name[i]=b[j];
		i+=2;
	}
	for(int i=1;i<=n;i++)cout<<name[i];
	
}