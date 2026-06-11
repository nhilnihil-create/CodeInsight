#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
int cl[120000],lst[120000];
vector<int> eds[120000];
int n,m,q,a,b,v,d,c;
void dfs1(int v,int d,int c)
{
	if (!cl[v]) cl[v]=c;
	if (lst[v]>=d) return;
	lst[v]=d;
	if (d==0) return;
	for (int u: eds[v]) dfs1(u, d - 1, c);
}
vector<tuple<int, int, int >> vv;
int main()
{
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		cin>>a>>b;
		--a, --b;
		eds[a].pb(b);
		eds[b].pb(a);
	}
	cin>>q;
	for (int i=0;i<q;i++)
	{
		cin>>v>>d>>c;
		--v;
		vv.pb(make_tuple(v, d, c));
	}
	reverse(vv.begin(),vv.end());
	for (int i=0;i<q;i++)
	{
		int v, d, c;
		tie(v, d, c) = vv[i];
		dfs1(v, d, c);
	}
	for (int i=0;i<n;i++) cout<<cl[i]<<endl;
	return 0;
}