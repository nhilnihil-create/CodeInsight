#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
vector<vl> graph;
ll A[101010];
ll n;
ll dfs(ll p,ll r)
{
	if(graph[p].size() == 1)		return A[p];
	vector <ll> X;
	ll s = 0;
	for(auto t: graph[p])
	{
		if(t != r)
		{
			ll x = dfs(t, p);
			s += x;
			X.push_back(x);
		}
	}
	if(s < A[p] || A[p] * 2 < s) 
	{
		printf("NO");
		exit(0);
	}
	if(*max_element(X.begin(), X.end()) > A[p]) 
	{
		printf("NO");
		exit(0);
	}
	return A[p] * 2 - s;
}
 
int main()
{
	ll i, u, v;
	scanf("%d",&n);
	graph.assign(n+1,vl());
	for(i=1;i<=n;i++)	scanf("%lld",&A[i]);
	for(i=1; i<n; i++)
	{
		scanf("%lld %lld",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	if(n == 2)
	{
		if(A[1] == A[2])		printf("YES");
		else					printf("NO");
		return 0;
	}
	for(i=1; i<=n; i++)
	{
		if(graph[i].size() > 1) 
		{
			break;
		}
	}
	int res = dfs(i,0);
	if(res==0)			printf("YES");
	else				printf("NO");
}