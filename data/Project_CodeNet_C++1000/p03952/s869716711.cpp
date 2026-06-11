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


const int N = (int) 2e5 + 100;
int a[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, x;
    scanf("%d%d", &n, &x);

    if (x == 1 || x == 2 * n - 1)
    {
        printf("No\n");
        return 0;
    }

    printf("Yes\n");

    a[n - 1] = x;
    a[n - 2] = x + 1;
    a[n] = x - 1;
    int cur = 1;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        while (abs(cur - x) <= 1)
            cur++;
        if (a[i] == 0)
            a[i] = cur++;
    }

    for (int i = 0; i < 2 * n - 1; i++)
        printf("%d\n", a[i]);


	return 0;
}


