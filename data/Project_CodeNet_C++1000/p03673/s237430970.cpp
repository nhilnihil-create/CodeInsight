
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
deque<int> q;
int32_t main()
{
	int n=in();
	int x;
	for(int i=0;i<n;i++)
	{
		x=in();
		if(i&1)q.push_front(x);
		else q.push_back(x);
	}
	vector<int> a;
	while(!q.empty())
	{
		a.push_back(q.front());
		q.pop_front();
	}
	if(n&1)reverse(all(a));
	for(auto i:a)cout<<i<<' ';
}