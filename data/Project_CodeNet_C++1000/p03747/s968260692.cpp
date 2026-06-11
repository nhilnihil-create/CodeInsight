#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100010;
int n, x[MAXN], a[MAXN], w[MAXN], L, T;
ll cur;

int main()
{
	scanf("%d%d%d", &n, &L, &T);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a[i], &w[i]);
		if(w[i] == 1)
		{
			x[i] = (a[i] + T) % L;
			cur += (a[i] + T) / L;
		}
		else
		{
			x[i] = (a[i] - T) % L;
			cur += (a[i] - T) / L;
			if(x[i] < 0)x[i] += L, --cur; 
		}
	}
	cur = (cur % n + n) % n;
	sort(x, x + n);
	for(int i = cur; i < n; ++i)printf("%d\n", x[i]);
	for(int i = 0; i < cur; ++i)printf("%d\n", x[i]);
	return 0;
}