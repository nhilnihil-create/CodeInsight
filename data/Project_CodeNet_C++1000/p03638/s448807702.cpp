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
	int h=in();int w=in();
	int n=in();
	vector<int> a(n);
	trav(i,a)i=in();
	vector<int> col;
	for(int i=0;i<n;i++)
	{
		while(a[i]--)col.push_back(i+1);
	}
	int cur=0;
	for(int i=0;i<h;i++)
	{
		vector<int> pr;
		for(int i=cur;i<cur+w;i++)pr.push_back(col[i]);
		if(i&1)reverse(all(pr));
		trav(i,pr)cout<<i<<" ";
		cout<<"\n";
		cur+=w;
		
	}
	
}