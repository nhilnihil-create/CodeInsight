#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LL MOD = 1000000007;
const int INF = 1000000007;
const LL LINF = 1LL * INF * INF;
const int MAXN = 507;
const LD EPS = 1e-7;

const int MAGIC = 1000;

int A[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	int n, m, h, w;
	cin >> n >> m >> h >> w;
	if (n % h == 0 && m % w == 0)
	{
		cout << "No";
		return 0;
	}
	int n1 = n / h * h, m1 = m / w * w, cnt = 0;
	LL s = 0;
	FOR(i, 1, n + 1)
		FOR(j, 1, m + 1)
	{
		if (i > n1 || j > m1)
		{
			++cnt;
			continue;
		}
		if (i % h == 0 && j % w == 0)
			A[i][j] = - (h * w - 1) * MAGIC - 1;
		else
			A[i][j] = MAGIC;
		s -= A[i][j];
	}
	++s;
	FOR(i, 1, n + 1)
		FOR(j, 1, m + 1)
	{
		if (i > n1 || j > m1)
		{
			A[i][j] = s / cnt;
			s -= A[i][j];
			--cnt;
		}
	}
	cout << "Yes\n";
	FOR(i, 1, n + 1)
	{
		FOR(j, 1, m + 1)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
	//cout << endl; system("pause");
	return 0;
}