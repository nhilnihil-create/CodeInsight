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


const int N = (int) 1e5 + 100;
long long x[N], d[N], ad[N];
int p[N];

const int LOG = 60;
int up[N][LOG];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &x[i]);
    
    for (int i = 0; i < n - 1; i++)
    {
        p[i] = i;
        d[i] = x[i + 1] - x[i];
    }


    int m;
    long long k;
    scanf("%d%lld", &m, &k);
    for (int i = 0; i < m; i++)
    {
        int xx;
        scanf("%d", &xx);
        xx -= 2;
        swap(p[xx], p[xx + 1]);
    }

    for (int i = 0; i < n - 1; i++)
        up[p[i]][0] = i;

    for (int j = 1; j < LOG; j++)
        for (int i = 0; i < n - 1; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    for (int i = 0; i < n - 1; i++)
    {
        int np = i;
        for (int j = 0; j < LOG; j++)
            if (k & (1LL << j))
                np = up[np][j];
        ad[np] = d[i];
    }

    for (int i = 0; i < n - 1; i++)
        x[i + 1] = x[i] + ad[i];

    for (int i = 0; i < n; i++)
        printf("%lld\n", x[i]);

	return 0;
}


