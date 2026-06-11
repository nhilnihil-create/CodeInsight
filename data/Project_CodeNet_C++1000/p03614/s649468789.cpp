/*
 * Author: madlogic
 * It's better to do something than nothing
*/
#include <bits/stdc++.h>
using namespace std;
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define watch(x) cout<<"->"<<#x<<" : "<<x<<endl;
// #define int long long
const int INF = 1000000000;
const int MOD = 1000000007;
const double PI = 2*acos(0.0);
signed main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int res = 0;
	for(int i=0;i<n-1;i++)
	{
		if(i==a[i]-1)
		{
			++res;
			swap(a[i],a[i+1]);
		}
	}
	if(a[n-1]-1==n-1)
		++res,swap(a[n-1],a[n-2]);
	cout<<res<<endl;
	return 0;	
}