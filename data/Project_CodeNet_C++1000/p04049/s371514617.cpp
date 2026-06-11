#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 2005;
vector <int> g[N];

int dfs(int v, int par, int d)
{
    int ans = 1;
    if (d == 0)
        return ans;
    for (int to : g[v])
        if (to != par)
            ans += dfs(to, v, d - 1);
    return ans;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    for (int v = 0; v < n; v++)
    {
        ans = max(ans, dfs(v, v, k / 2));
        for (int to : g[v])
        {
            ans = max(ans, dfs(v, to, (k - 1) / 2) + dfs(to, v, (k - 1) / 2));
        }
    }
    
    printf("%d\n", n - ans);

	return 0;
}


