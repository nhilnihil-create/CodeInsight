#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int A[100005],id[100005],vis[100005];
int cur[100005],id2[100005];ll k;
void sv(int a)
{
	int t = id[a];
	int c = 0;
	cur[++ c] = a;vis[a] = 1; 
	while(t != a)
		cur[++ c] = t,vis[t] = 1,t = id[t];
	int r = k%c;
	for(int i = 1;i <= c;i ++)
		id2[cur[i]] = cur[(i+r-1)%c+1];
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&A[i]),id[i] = i;
	scanf("%d%lld",&m,&k);
	for(int i = 1;i <= m;i ++)
	{
		int a;
		scanf("%d",&a);
		swap(id[a],id[a+1]);
	}
	for(int i = 1;i <= n;i ++)
		if(!vis[i])
			sv(i);
	ll t = A[1];printf("%lld.0\n",t); 
	for(int i = 2;i <= n;i ++)
	{
		t += A[id2[i]]-A[id2[i]-1];
		printf("%lld.0\n",t);
	}
	return 0;
}