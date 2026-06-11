#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100005;

#define int long long

typedef long long LL;

int n, m;
LL k;
int x[maxn];
int cf[maxn];
int one[maxn];
int ans[maxn];
int tmp[maxn];

inline void zh()
{
	for(int i = 1; i < n; ++i)
		tmp[i] = one[one[i]];
	for(int i = 1; i < n; ++i)
		one[i] = tmp[i];
}

inline void zh2()
{
	for(int i = 1; i < n; ++i)
		tmp[i] = ans[one[i]];
	for(int i = 1; i < n; ++i)
		ans[i] = tmp[i];
}

inline void pow(LL k)
{
	for(int i = 1; i < n; ++i)
		ans[i] = i;
	for(; k; zh(), k >>= 1)
		if(k & 1)
			zh2();
}

inline void getone()
{
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld", &x[i]);
		one[i] = i;
	}
	scanf("%lld%lld", &m, &k);
	for(int i = 1, a; i <= m; ++i)
	{
		scanf("%lld", &a);
		swap(one[a - 1], one[a]);
	}
	pow(k);
	for(int i = 1; i < n; ++i)
		cf[i] = x[i + 1] - x[i];
//	for(int i = 1; i < n; ++i)
//		printf("%lld ", cf[i]);
//	puts("");
	for(int i = 1; i < n; ++i)
		tmp[i] = cf[ans[i]];
//	for(int i = 1; i < n; ++i)
//		printf("%lld ", tmp[i]);
//	puts("");
	printf("%lld.0\n", x[1]);
	for(int i = 2; i <= n; ++i)
	{
		x[i] = x[i - 1] + tmp[i - 1];
		printf("%lld.0\n", x[i]);
	}
}

signed main()
{
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	getone();
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}