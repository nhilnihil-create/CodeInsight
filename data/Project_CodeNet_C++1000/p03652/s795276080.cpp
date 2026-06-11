/*
 * File Name:	B.cpp
 * Author	:	CraZYali
 * Year		:	2019.10.23 23:36
 * Email	:	yms-chenziyang@outlook.com
 */

#define DREP(i, s, e) for (register int i(s), end_##i(e); i >= end_##i; i--)
#define  REP(i, s, e) for (register int i(s), end_##i(e); i <= end_##i; i++)
#define DEBUG fprintf(stderr, "Passing [%s] in Line %d\n", __FUNCTION__, __LINE__)

#define chkmax(a, b) a = max(a, (b))
#define chkmin(a, b) a = min(a, (b))

#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 300 + 5, maxm = 300 + 5;

template <typename T> inline T read()
{
	T ans(0), flag(1);
	char c(getchar());
	while (!isdigit(c))
	{
		if (c == '-') flag = -1;
		c = getchar();
	}
	while (isdigit(c))
	{
		ans = ans * 10 + c - 48;
		c = getchar();
	}
	return ans * flag;
}

#define file(FILE_NAME) freopen(FILE_NAME".in", "r", stdin), freopen(FILE_NAME".out", "w", stdout);

int n, m, fav[maxn][maxm];

bool pick[maxn];
int cnt[maxn];

int main()
{
#ifdef CraZYali
	file("B");
#endif
	cin >> n >> m;
	REP(i, 1, n)
		REP(j, 1, m) fav[i][j] = read<int>();
	REP(i, 1, m) pick[i] = 1;
	int ans = 1e9;
	REP(times, 1, m)
	{
		REP(j, 1, m) cnt[j] = 0;
		REP(i, 1, n)
			REP(j, 1, m)
				if (pick[fav[i][j]])
				{
					cnt[fav[i][j]]++;
					break;
				}
		int k = 1;
		REP(j, 2, m) if (cnt[j] > cnt[k]) k = j;
		chkmin(ans, cnt[k]);
		pick[k] = 0;
	}
	cout << ans << endl;
	return 0;
}
