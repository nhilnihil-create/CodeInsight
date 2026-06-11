//14:07:00 

#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define int ll
using namespace std;
using ll=long long;
using pii=pair<int,int>;



int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin>>n;
	vector<int> v(n*3);
	for(auto &i:v) cin>>i;
	priority_queue<int,vector<int>,greater<int>> pqs;
	vector<int> pre; int now=0;
	For(i,0,n-1)
	{
		now+=v[i];
		pqs.emplace(v[i]);
	} pre.emplace_back(now);
	For(i,n,n*2-1)
	{
		pqs.emplace(v[i]);
		now+=v[i];
		now-=pqs.top();
		pqs.pop();
		pre.emplace_back(now);
	}
	priority_queue<int> pqb;
	vector<int> suf; now=0;
	for(int i=n*3-1;i>=n*2;i--)
	{
		now+=v[i];
		pqb.emplace(v[i]);
	} suf.emplace_back(now);
	for(int i=n*2-1;i>=n;i--)
	{
		pqb.emplace(v[i]);
		now+=v[i];
		now-=pqb.top();
		pqb.pop();
		suf.emplace_back(now);
	}
	int mx=-1e17;
	For(i,0,sz(pre)-1)
		mx=max(mx,pre[i]-suf[sz(suf)-i-1]);
	cout<<mx<<"\n";
	//for(auto i:pre) cout<<i<<" "; cout<<"\n";
	//for(auto i:suf) cout<<i<<" "; cout<<"\n";
	return 0;
}









