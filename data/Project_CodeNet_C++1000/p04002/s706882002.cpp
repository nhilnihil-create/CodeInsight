#include<bits/stdc++.h>
using namespace std;
typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int U=1e9+7;
unordered_map<s64,int>mp;
int ans[10];
int main()
{
	int h,w,n;
	cin>>h>>w>>n;
	rep(i,1,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		rep(x1,max(1,x-2),min(x,h-2))
		rep(y1,max(1,y-2),min(y,w-2))++mp[(s64)x1*U+y1];
	}
	for(auto pr:mp)++ans[pr.second];
	printf("%lld\n",(s64)(h-2)*(w-2)-mp.size());
	rep(i,1,9)printf("%d\n",ans[i]);
}