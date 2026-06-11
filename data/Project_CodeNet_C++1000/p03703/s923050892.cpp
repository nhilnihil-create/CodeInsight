#include<bits/stdc++.h>
using namespace std;
struct tr
{
	int t[202020];
	void gx(int xh,int vl)
	{
		xh++;
		while(xh<202020)
		{
			t[xh]+=vl;
			xh+=xh&-xh;
		}
	}
	int gt1(int xh)
	{
		xh++;
		int ans=0;
		while(xh>0)
		{
			ans+=t[xh];
			xh-=xh&-xh;
		}
		return ans;
	}
};
tr tt;
int n;
long long k,cnt[202020],ans;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>cnt[i];
		cnt[i]-=k;
		cnt[i]+=cnt[i-1];
	}
	vector<long long>v;
	for(int i=0;i<=n;i++)
	{
		v.push_back(cnt[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<=n;i++)
	{
		int p=lower_bound(v.begin(),v.end(),cnt[i])-v.begin();
		ans+=tt.gt1(p);
		tt.gx(p,1);
	}
	cout<<ans<<endl;
	return 0;
}