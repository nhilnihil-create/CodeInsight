#include <bits/stdc++.h>
 
#define forn(i, n) for (llong i = 0ll; i < (llong) n; ++i)
#define fornn(i, l, r) for (llong i = (llong) l; i < (llong) r; ++i)
#define size(x) ((int) (x.size()))
 
using namespace std;
 
typedef long long llong;
const llong inf = (llong) 1e+9 + 7ll;
const llong linf = (llong) 1e+18 + 7ll;
const long double eps = (long double) 1e-9;
const long double pi = acosl((long double) -1.0);
const int alph = 26;

mt19937 mrand(random_device{} ()); 

template<typename T, typename U> inline llong umin(const T& a, const U& b) { return a < b ? a : b; }
template<typename T, typename U> inline llong umax(const T& a, const U& b) { return a > b ? a : b; }
 
static char buff[(int) 2e6 + 17]; // reads std::string
const int maxn = (int) 1e5 + 17;

int n;
vector<int> g[maxn];

bool read()
{
	if (scanf("%d", &n) != 1)
		return false;

	forn (i, n - 1)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	return true;
}

int dfs(int v, int pr)
{
	int gr = 0;
	
	for (auto to : g[v])
		if (to != pr)
			gr ^= dfs(to, v);

	return gr + 1;
}

void solve()
{
	if (dfs(0, -1) == 1)
		printf("Bob\n");
	else
		printf("Alice\n");
}

int main()
{
#if SEREZHKA
	freopen("file.in", "r", stdin);
#endif

	while (read())
		solve();

	return 0;
}
