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




int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    long long ans = 0;
    long long rem = 0;
    for (int i = 0; i < n; i++)
    {
        long long cur;
        scanf("%lld", &cur);
        if (rem && cur)
        {
            cur--;
            ans++;
        }
        long long x = cur / 2;
        ans += x;
        cur -= 2 * x;
        rem = cur;
    }
    printf("%lld\n", ans);




	return 0;
}


