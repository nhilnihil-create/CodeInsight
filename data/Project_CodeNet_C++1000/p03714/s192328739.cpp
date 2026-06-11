#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
typedef long long LL;
const int MaxN = 3e5 + 5;
 
LL n, a[MaxN];
LL pre[MaxN], tail[MaxN];
 
int main()
{
	while(~scanf("%lld", &n))
	{
		for(int i = 1; i <= 3 * n; i++) scanf("%lld", &a[i]);
		priority_queue<LL, vector<LL>, greater<LL> > pq1;
		priority_queue<LL, vector<LL>, less<LL> > pq2;
		LL pp = 0, tt = 0;
		for(int i = 1; i <= n; i++) 
		{
			pq1.push(a[i]);
			pp += a[i];
		}
		pre[n] = pp;
		for(int i = 2 * n + 1; i <= 3 * n; i++) 
		{
			pq2.push(a[i]);
			tt += a[i];
		}
		tail[2 * n + 1] = tt;
		for(int i = n + 1; i <= 2 * n; i++)
		{
			pq1.push(a[i]);
			LL x = pq1.top();
			pq1.pop();
			pp -= (x - a[i]);
			pre[i] = pp;
			//printf("%d : %lld\n", i, pre[i]);
		}
		for(int i = 2 * n; i >= n + 1; i--)
		{
			pq2.push(a[i]);
			LL x = pq2.top();
			pq2.pop();
			tt -= (x - a[i]);
			tail[i] = tt;
			//printf("%d: %lld\n", i, tail[i]);
		}
		LL ma = -1e16;
		for(int i = n; i <= 2 * n; i++)
		{
			ma = max(ma, pre[i] - tail[i + 1]);
		}
		printf("%lld\n", ma);
	}	
	return 0;
}