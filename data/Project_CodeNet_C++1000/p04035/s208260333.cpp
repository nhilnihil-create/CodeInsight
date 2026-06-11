#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int pos=-1;
	for(int i=1;i<n;i++)
	{
		if(a[i]+a[i+1]>=k)
		{
			pos=i;
			break;
		}
	}
	if(pos==-1)
	{
		return cout<<"Impossible"<<endl,0;
	}
	cout<<"Possible"<<endl;
	for(int i=1;i<pos;i++)cout<<i<<endl;
	for(int i=n-1;i>pos;i--)cout<<i<<endl;
	cout<<pos<<endl;
	return 0;
}