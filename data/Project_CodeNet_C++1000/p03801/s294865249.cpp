#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
const int N = 1e5+1;
int i,n,a[N],sz[N];
ll ans[N];
priority_queue<ii>pq;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pq.push(ii(a[i],i));
		sz[i] = 1;
	}
	while(pq.size()>1)
	{
		int t1 = pq.top().first;
		int i1 = pq.top().second;
		pq.pop();
		int t2 = pq.top().first;
		int i2 = pq.top().second;
		pq.pop();
		ans[i1] += 1ll * sz[i1] * (t1 - t2);
		pq.push(ii(t2,min(i1,i2)));
		sz[min(i1,i2)] += sz[max(i1,i2)]; 
	}
	ans[1] += 1ll * n * pq.top().first;
	for(i=1;i<=n;i++)	printf("%lld\n",ans[i]);
}