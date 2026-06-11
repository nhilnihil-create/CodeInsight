#include<bits/stdc++.h>
using namespace std;
long long arr[1000000];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    long long n,x,i,j,k,y,z,ans;
    cin>>n>>x;
    ans=0;
    for (i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	for (i=0;i<n-1;i++)
	{
		y=arr[i]+arr[i+1];
		if (y>x)
		{
			z=y-x;
			ans+=z;
			if (arr[i+1]>=z)
			{
				arr[i+1]-=z;
			}
			else
			{
				arr[i+1]=0;
				z-=arr[i+1];
				arr[i]-=z;
			}
		}
	}
	cout<<ans<<endl;
}