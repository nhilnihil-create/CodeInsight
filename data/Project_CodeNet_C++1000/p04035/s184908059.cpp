#include<bits/stdc++.h>
#define ll long long
#define mod pow(10,9)+7
#define lim pow(10,7)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,l;
	cin>>n>>l;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int flag=0;
	for(int i=0;i<n-1;i++)
		if(a[i]+a[i+1]>=l)
			flag=i+1;
	if(flag)
	{
		cout<<"Possible"<<endl;
		for(int i=n-1;i>flag;i--)
			cout<<i<<endl;
		for(int i=1;i<=flag;i++)
			cout<<i<<endl;
	}
	else
		cout<<"Impossible"<<endl;
	return 0;
}
