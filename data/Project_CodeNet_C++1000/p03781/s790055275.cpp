#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans,n,m;
signed main()
{
	cin>>n;
	int l=0,r=100000; 
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(mid*(mid+1)/2>=n)ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;	

}
/*
fij表示前i个数是否能凑到j。
对于i，可选择正着跳/反着跳/不跳
fij=fi-1,j-i|fi-1,j+i|fi-1,j
然后我们考虑打表 
打表可以知道，对于一个数x，如果存在n*(n-1)/2<x<=n*(n+1)/2，答案就是n 于是你二分就好。 
*/