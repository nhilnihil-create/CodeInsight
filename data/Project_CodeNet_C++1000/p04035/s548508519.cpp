#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int N,L;
	cin>>N>>L;
	long long int arr[N],len[N];
	for(long long int i=1;i<=N;i++)
	{
		cin>>arr[i];
	}
	bool flag=0;
	long long int index=0;
	for(long long int i=1;i<=N-1;i++)
	{
		len[i]=arr[i]+arr[i+1];
		if(len[i]>=L)
			{
				flag=1;
				index=i;
			}
	}
	if(flag)
	{
		cout<<"Possible"<<endl;
		for(long long int i=1;i<index;i++)
		{
			cout<<i<<endl;
		}
		for(long long int i=N-1;i>=index+1;i--)
		{
			cout<<i<<endl;
		}
		cout<<index<<endl;
	}
	else
	{
		cout<<"Impossible"<<endl;
	}

	return 0;
}