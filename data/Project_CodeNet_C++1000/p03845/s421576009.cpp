#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#define ll long long
using namespace std;
const int N=110;
int arr[N],brr[N];
int main() 
{
	int n;
	while(cin>>n)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];	
			ans+=arr[i];
		}
		int m,p,x;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>p>>x;
			cout<<ans-arr[p]+x<<"\n";
		}
	}
	return 0;
}
