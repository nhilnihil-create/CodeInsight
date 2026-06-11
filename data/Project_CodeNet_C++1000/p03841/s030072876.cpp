#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int maxm = maxn * maxn;
#define mp(a, b) make_pair(a, b)
typedef pair<int, int> pii;
pii e[maxn];
int n, m;
int a[maxn], b[maxm];
queue<int> cand;
void no() { puts("No"); exit(0);}
int main()
{
	scanf("%d", &n);
	m = n * n;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		e[i] = mp(a[i], i);
		b[a[i]] = i;
	}
	for(int i = 1; i <= m; ++i) 
		if(!b[i])
			cand.push(i); 
	sort(e + 1, e + n + 1);
	for(int i = 1; i <= n; ++i)
	{
		int res = e[i].second - 1;
		while(res--)
		{
			int x = cand.front(); cand.pop();
			if(x > e[i].first) no();
			b[x] = e[i].second;
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		int res = n - e[i].second;
		while(res--)
		{
			int x = cand.front(); cand.pop();
			if(x < e[i].first) no();
			b[x] = e[i].second;
		}
	}
	puts("Yes");
	for(int i = 1; i <= m; ++i) printf("%d ", b[i]);
	puts("");
	return 0;
}
	