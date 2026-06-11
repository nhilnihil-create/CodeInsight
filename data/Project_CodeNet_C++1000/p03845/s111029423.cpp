#include<bits/stdc++.h>

using namespace std;

int main()
{
	  #ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);

	  #endif
	  int n;
	  cin>>n;
	  long long arr[n];
	  long long sum=0;
	  for(int i=0;i<n;i++)
	  {
	  	cin>>arr[i];
	  	sum+=arr[i];
	  }
	  int t;
	  cin>>t;
	  while(t--)
	  {
	  		long long a,b;
	  		cin>>a>>b;
	  		cout<<sum-arr[a-1]+b<<"\n";
	  }
}