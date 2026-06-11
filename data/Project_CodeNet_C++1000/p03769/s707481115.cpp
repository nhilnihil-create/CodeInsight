#include <bits/stdc++.h>
#define LL long long
using namespace std;
int Cnt, A[1000001];
LL N;
LL h, t;

inline void dfs (LL x)
{
	if (x == 1) {h = 1000, t = 999;return ;}
	if (x % 2) 
	{
		dfs(x - 1);
		A[--h] = ++Cnt;
	}
	else
	{
		dfs(x / 2);
		A[++t] = ++Cnt;
	}
}

int main()
{
#ifdef hk_cnyali
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	scanf("%lld", &N);
	dfs(N + 1);
	cout<<Cnt * 2<<endl;
	for (int i = h; i <= t; ++i)
		cout<<A[i]<<" ";
	for (int i = 1; i <= Cnt; ++i)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}