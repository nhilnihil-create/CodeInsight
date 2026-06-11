#include<bits/stdc++.h>
using namespace std;
int a[200010],inn[200010];
vector <int> des[200010];
int dfs(int s,int pre)
{
	if (inn[s]==1) return a[s];
	vector <int> vec;long long sum=0;
	for (int k=0;k<des[s].size();k++) if (des[s][k]!=pre)
	{
		int d=dfs(des[s][k],s);
		sum+=d;if (d>a[s]) {puts("NO");exit(0);}
	}
	if ((sum>2*a[s])||(sum<a[s])) {puts("NO");exit(0);}
	return 2*a[s]-sum;
}
int main()
{
	int n;scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n==2) {puts((a[1]==a[2])?"YES":"NO");return 0;}
	for (int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		des[u].push_back(v);des[v].push_back(u);
		inn[u]++;inn[v]++;
	}
	int root=1;while (inn[root]==1) root++;
	if (dfs(root,0)) {puts("NO");exit(0);}
	puts("YES");
}