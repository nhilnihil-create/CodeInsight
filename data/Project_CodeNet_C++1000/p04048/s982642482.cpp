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


long long solve(long long a, long long b)
{
    if (a == 0 || b == 0)
        return 0;
    if (a == b)
        return a + b;
    if (a < b)
        return a + b + solve(b - a, a);
    
    long long k = a / b;
    return 2 * k * b + solve(a - k * b, b);
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    long long n, x;
    scanf("%lld%lld", &n, &x);

    long long ans = x + solve(x, n - x);
    printf("%lld\n", ans);


	return 0;
}


