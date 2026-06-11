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


const int N = 2005;
long long a[2 * N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    long long x;
    scanf("%d%lld", &n, &x);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        a[n + i] = a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i];

    for (int sh = 1; sh < n; sh++)
    {
        long long cur = sh * x;
        multiset <long long> s;

        for (int i = 0; i < sh; i++)
            s.insert(a[n - 1 - i]);

        for (int i = n; i < 2 * n; i++)
        {
            s.insert(a[i]);
            cur += *s.begin();
            s.erase(s.find(a[i - sh]));
        }
        ans = min(ans, cur);
    }
    printf("%lld\n", ans);

	return 0;
}


