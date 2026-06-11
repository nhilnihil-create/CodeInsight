#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int n=in();int x;
	vector<int> rt;
	int cur=0;
	vector<int> a(3*n);
	trav(i,a)i=in();
	priority_queue<int> mn;//minus minus
	for(int i=0;i<n;i++){cur+=a[i];mn.push(-a[i]);}
	rt.push_back(cur);
	for(int i=n;i<2*n;i++)
	{
		x=a[i];
		if(x>-mn.top())
		{
			cur+=mn.top();
			cur+=x;
			mn.pop();
			mn.push(-x);
			rt.push_back(cur);
		}
		else rt.push_back(cur);
	}
	priority_queue<int> mx;//plus plus
	//trav(i,rt)cout<<i<<' ';
	vector<int> lt;
	cur=0;
	for(int i=3*n-1;i>=2*n;i--){cur+=a[i];mx.push(a[i]);}
	lt.push_back(cur);
	for(int i=2*n-1;i>=n;i--)
	{
		x=a[i];
		if(x<mx.top())
		{
			cur-=mx.top();
			cur+=x;
			mx.pop();
			mx.push(x);
			lt.push_back(cur);
		}
		else lt.push_back(cur);
	}
	reverse(all(lt));
	int ans=-1e18;
	for(int i=0;i<lt.size();i++)ans=max(ans,rt[i]-lt[i]);
	cout<<ans;
	
	
	
	
}