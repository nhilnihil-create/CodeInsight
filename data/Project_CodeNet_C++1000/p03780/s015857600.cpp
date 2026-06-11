#include<iostream>
#include<algorithm>
using namespace std;
int n,k,a[5000];
int dp[5050][5050]={1};
bool C(int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)dp[i+1][j]=0;
		for(int j=0;j<k;j++)
		{
			if(dp[i][j]){
				dp[i+1][j]=1;
				if(i!=m&&j+a[i]<k)dp[i+1][j+a[i]]=1;
			}
		}
	}
	for(int i=max(0,k-a[m]);i<k;i++)if(dp[n][i])return true;
	return false;
}
main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int l=0,f=n+1,m;
	while(f-l>1)
	{
		m=(f+l)/2;
		(C(m-1)?f:l)=m;
	}
	cout<<l<<endl;
}