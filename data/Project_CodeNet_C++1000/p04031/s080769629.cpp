#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1
int solve(vector<int>&arr, int to)
{
	int ret = 0;
	for(int x:arr){
		ret+=(x-to)*(x-to);
	}
	return ret;
}
int main()
{	
	ios_base::sync_with_stdio(0);
	int n;
	while(cin>>n){
		vector<int> arr(n);
		for(int i=0; i<n; i++)
			cin>>arr[i];
		int ans =1000000000;
		for(int i=-100; i<=100; i++){
			ans = min(ans, solve(arr,i));
		}
		cout<<ans<<endl;
	}
}

