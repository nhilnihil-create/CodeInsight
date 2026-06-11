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

int a[N], b[N];
    
int n;

bool check()
{
    for (int i = 0; i < 2 * n - 1; i++)
        eprintf("%d ", b[i]); eprintf("\n");

    int l = n - 1, r = n - 1;
    while (l > 0 && b[l - 1] != b[l])
        l--;
    while (r + 1 < 2 * n - 1 && b[r + 1] != b[r])
        r++;

    if (b[l] == b[r])
        return b[l];
    if (r - (n - 1) < (n - 1) - l)
        return b[r];
    return b[l];
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 1; i++)
        scanf("%d", &a[i]);

    int lb = 1, rb = 2 * n;
    while (rb - lb > 1)
    {
        int mb = (lb + rb) / 2;

        for (int i = 0; i < 2 * n - 1; i++)
            b[i] = (mb <= a[i]);
    
        if (check())
            lb = mb;
        else
            rb = mb;
    }

    printf("%d\n", lb);


	return 0;
}


