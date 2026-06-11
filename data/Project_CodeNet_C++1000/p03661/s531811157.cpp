#include<bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(0); 	
	cout.tie(0); 
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int nums[n];
	long long sum[n];
	cin>>nums[0];
	sum[0]=nums[0]; 
	for(int i = 1; i < n; i++)
	{
		cin >> nums[i];
        sum[i]=sum[i-1]+nums[i];
	}
	
	long long min = abs(sum[n-1] - 2*sum[0]);
	for(int i = 1; i < n-1; i++)
	{
		if(min>abs(sum[n-1] - 2*sum[i]))
			min = abs(sum[n-1] - 2*sum[i]);		
	}	
	cout << min;		
}