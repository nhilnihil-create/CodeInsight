#include<iostream>
using namespace std;
#include<vector>
#define int long long int
int32_t main()
{
	int n;
	cin>>n;
	int x;
	cin>>x;
	int j,arr[n];
	for(j=0;j<n;j++)
	     cin>>arr[j];
	int answer=0;
	for(j=1;j<n;j++)
	{
		if(arr[j]+arr[j-1]>x)
		{
			int diff=-(x-arr[j]-arr[j-1]);
			answer+=diff;
			if(arr[j]>=diff)
			{
				arr[j]-=diff;
			}
			else
			   arr[j]=0;
		}	
	}
	cout<<answer<<endl;
}
