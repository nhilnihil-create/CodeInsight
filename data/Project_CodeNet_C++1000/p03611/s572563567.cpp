#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	unordered_map<int,int> store;	
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		store[x]++;
	}
	int ans=0;
	for(int i=0;i<100000;i++)
	{
		int temp=0;
		for(int j=-1;j<=1;j++)
			temp+=store[i+j];
		ans=max(ans,temp);
	}
	cout<<ans;
	return 0;
}
