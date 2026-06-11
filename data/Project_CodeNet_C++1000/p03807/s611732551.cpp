#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,i,j;
	cin>>n;
	long long int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	{
		j=j+a[i];
	}
	if(j%2==0)
	cout<<"YES"<<endl;
	if(j%2!=0)
	cout<<"NO"<<endl;
	return 0;
}