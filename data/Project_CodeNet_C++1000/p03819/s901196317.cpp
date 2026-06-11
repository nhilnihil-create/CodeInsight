#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, m, current=0;
int l[N], r[N], ans[N];
int bit[N];
map<int, vector<pair<int, int> > > event;

void update(int idx, int val)
{
	while(idx<=m)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=idx&-idx;
	}
	return ans;
}

int rsum(int l, int r)
{
	return pref(r) - pref(l-1);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		event[r[i]-l[i]+1].push_back({l[i], r[i]});
		update(l[i], +1);
		update(r[i]+1, -1);
	}
	for(int i=m;i>=1;i--)
	{
		for(auto &it:event[i])
		{
			current++;
			update(it.first, -1), update(it.second+1, 1);
		}
		for(int j=0;j*i<=m;j++)
			ans[i]+=pref(j*i);	
		ans[i]+=current;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}
