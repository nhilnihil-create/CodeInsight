#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int pre[100005];
int pos[100005];


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

	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
		pos[i]=pos[i-1]+max(a[i],0LL);
	}
	int mx=0;
	for(int i=k;i<=n;i++)
	{
		mx=max(mx,pos[i-k]+pos[n]-pos[i]);
		mx=max(mx,pos[i-k]+pos[n]-pos[i]+pre[i]-pre[i-k]);
	}
	cout<<mx;
}
