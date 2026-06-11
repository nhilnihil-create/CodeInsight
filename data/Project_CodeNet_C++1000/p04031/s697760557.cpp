#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,s=0,k,m=0,n=0;
	cin>>a;
	int b[a];
	for(int i=1;i<=a;i++)
	{
		cin>>b[i];
		s+=b[i];
	}
	k=s/a;
	for(int i=1;i<=a;i++) 
	{
		m+=(k-b[i])*(k-b[i]);
		n+=(k+1-b[i])*(k+1-b[i]);
	}
	if(m>n)
	swap(m,n);
	cout<<m<<endl;
	return 0;
}