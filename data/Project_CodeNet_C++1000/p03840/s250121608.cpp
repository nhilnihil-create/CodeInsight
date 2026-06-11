#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int ans[1000000];
int cnt[505];
int mm[1000005];

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
	if(fopen("INPUT.txt","r"))
	{
	freopen ("INPUT.txt" , "r" , stdin);
	freopen ("OUTPUT.txt" , "w" , stdout);
	}
#endif  

	int a[7];
	for(int i=0;i<7;i++)
		cin>>a[i];
	int ans=0;
	ans+=a[1];
	if(a[0]==0||a[3]==0||a[4]==0)
	{
		int z=(a[0]/2+a[3]/2+a[4]/2)*2;
		ans+=z;
	}
	else
	{
		int x=a[0]%2;
		int y=a[3]%2;
		int z=a[4]%2;
		if(x==y&&x==z)
		{
			ans+=(a[0]+a[3]+a[4]);
		}
		else 
		{
			ans+=(a[0]+a[3]+a[4])-1;
		}
	}
	cout<<ans;
}
