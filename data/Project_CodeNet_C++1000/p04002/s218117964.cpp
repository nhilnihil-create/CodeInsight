#include<bits/stdc++.h>
using namespace std;
long long h,w,n,a[100005],b[100005],ans[10],cnt,l,r,dx[]={1,1,1,0,0,0,-1,-1,-1},dy[]={1,0,-1,1,0,-1,1,0,-1};
map<pair<long long,long long>,long long> mp;
set<pair<long long,long long> > s;
set<pair<long long,long long> > :: iterator it;
int main()
{
	scanf("%lld%lld%lld",&h,&w,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		mp[make_pair(a[i],b[i])]=1;
		for(int j=0;j<9;j++)
		{
			if(a[i]+dx[j]>1&&a[i]+dx[j]<h&&b[i]+dy[j]>1&&b[i]+dy[j]<w)
			{
				s.insert(make_pair(a[i]+dx[j],b[i]+dy[j]));
			}
		}
	}
	for(it=s.begin();it!=s.end();it++)
	{
		l=(*it).first;
		r=(*it).second;
		cnt=0;
		for(int j=0;j<9;j++)
		{
			if(mp[make_pair(l+dx[j],r+dy[j])]==1)
			{
				++cnt;
			}
		}
		++ans[cnt];
	}
	ans[0]=(h-2)*(w-2)-s.size();
	for(int i=0;i<=9;i++)
	{
		printf("%lld\n",ans[i]);
	}
}