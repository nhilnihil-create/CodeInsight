#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL Maxn = 100000 + 100;
LL A[Maxn], d[Maxn], P[Maxn];
LL Tmp[Maxn], Ans[Maxn];
LL N, M;
LL K;
inline void Pow()
{
	LL b = K;
	for (LL i = 1; i <= N; ++i) Ans[i] = i;
	while (b)
	{
		if (b & 1)
		{
			for (LL i = 1; i <= N; ++i) Tmp[i] = Ans[P[i]];
			for (LL i = 1; i <= N; ++i) Ans[i] = Tmp[i];
		}
		for (LL i = 1; i <= N; ++i) Tmp[i] = P[P[i]];
		for (LL i = 1; i <= N; ++i) P[i] = Tmp[i];
		b >>= 1;
	}
	for (LL i = 1; i <= N; ++i) Tmp[i] = d[Ans[i]];
	for (LL i = 1; i <= N; ++i) d[i] = Tmp[i];
}
int main()
{
#ifdef hk_cnyali
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	scanf("%lld", &N);
	for (LL i = 1; i <= N; ++i)
		scanf("%lld", &A[i]), d[i] = A[i] - A[i - 1];
	scanf("%lld %lld", &M, &K);
	for (LL i = 1; i <= N; ++i) P[i] = i;
	for (LL i = 1; i <= M; ++i)
	{
		LL x; scanf("%lld", &x);
		swap(P[x], P[x + 1]);
	}
	Pow();
	LL Sum = 0;
	for (LL i = 1; i <= N; ++i)
	{
		Sum += d[i];
		cout<<Sum<<endl;
	}
	return 0;
}