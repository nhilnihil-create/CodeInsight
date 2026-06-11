#pragma region Template
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <complex>
#include <regex>
#include <numeric>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#define mp make_pair
#define rand govno_ebanoe
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cerr << #x << " : " << (x) << endl
#define print_array(arr, len) {cerr << #arr << " : "; for(int i = 0; i < len; ++i) cerr << arr[i] << ' '; cerr << endl;}
#define print_2d_array(arr, len1, len2) {cerr << #arr << endl; for(int i = 0; i < len1; ++i, cerr << endl) for(int j = 0; j < len2; ++j) cerr << arr[i][j] << ' ';}
#define print_iterable(i) {cerr << #i << " : "; for(auto e : i) cerr << e << ' '; cerr << endl;}
#define print_new_line() cerr << endl

template <typename T, typename Q>
void print_pair1(pair<T, Q> x)
{
	cerr << "(" << x.first << ", " << x.second << ")\n";
}

#define print_pair(x) {cerr << #x << " : "; print_pair1(x);}
#else
#define print_pair(x) (void)0
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) {}
#define print_2d_array(arr, len1, len2) {}
#define print_iterable(i) {}
#define print_new_line() (void)0
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int INF = (int)1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;
#pragma endregion

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

const int N = 510;
char ans[N][N];
int n, m, d;
char tox[256];
char toy[256];

void solve_odd()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if ((i + j) % 2 == 0)
				ans[i][j] = 'R';
			else
				ans[i][j] = 'G';
}

void fill_sq(int x, int y, char c, int tx, int ty)
{
	if (x < 0 || x >= n || y < 0 || y >= m || ans[x][y])
		return;
	ans[x][y] = c;
	if (tx > 0)
		fill_sq(x + 1, y + 1, c, tx - 1, ty);
	else
		fill_sq(x + 1, y + 1, tox[c], d - 1, ty);
	if (tx + 1 < d)
		fill_sq(x - 1, y - 1, c, tx + 1, ty);
	else
		fill_sq(x - 1, y - 1, tox[c], 0, ty);
	if (ty > 0)
		fill_sq(x + 1, y - 1, c, tx, ty - 1);
	else
		fill_sq(x + 1, y - 1, toy[c], tx, d - 1);
	if (ty + 1 < d)
		fill_sq(x - 1, y + 1, c, tx, ty + 1);
	else
		fill_sq(x - 1, y + 1, toy[c], tx, 0);
}

void solve_ev()
{
	d /= 2;
	fill_sq(0, 0, 'R', d - 1, d - 1);
	fill_sq(1, 0, 'R', d - 1, d - 1);
}

void solve()
{
	tox['R'] = 'G';
	tox['G'] = 'R';
	tox['B'] = 'Y';
	tox['Y'] = 'B';
	toy['R'] = 'B';
	toy['B'] = 'R';
	toy['G'] = 'Y';
	toy['Y'] = 'G';
	scanf("%d%d%d", &n, &m, &d);
	if (d % 2 == 1)
		solve_odd();
	else
		solve_ev();
	for (int i = 0; i < n; ++i)
		puts(ans[i]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef NOERR
	freopen("err.txt", "w", stderr);
#endif
#else
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

#ifdef ERR_CATCH
	try
	{
#endif

#ifdef ST
		while (true)
			solve();
#endif
#ifdef CASES
#define MULTITEST
#endif
#ifdef MULTITEST
		int t;
		scanf("%d", &t);
		char endl1[5];
		fgets(endl1, 5, stdin);
		for (int i = 0; i < t; ++i)
		{
#ifdef CASES
			printf("Case #%d: ", i + 1);
#endif
			solve();
#ifdef CASES
			eprintf("Passed case #%d:\n", i + 1);
#endif
		}
#else
		solve();
#endif

#ifdef ERR_CATCH
	}
	catch (logic_error e)
	{
		print_var(e.what());
		puts("___________________________________________________________________________");
		exit(0);
	}
#endif
#ifdef LOCAL
	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
#endif
}