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


const int N = 105;
int a[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);

    bool good = true;
    if (n != 2)
    {
        if (a[2] == a[0])
            good = false;

        int it = 1;
        if (a[0] == a[1])
        {
            if (a[n - 1] != 2 * a[0] - 1)
                good = false;
            it++;
        }
        else
        {
            if (a[n - 1] != 2 * a[0])
                good = false;
        }
        while (it < n)
        {
            if (a[it] != a[it - 1] + 1)
            {
                good = false;
                break;
            }
            if (a[it] != a[it + 1])
            {
                good = false;
                break;
            }
            while (a[it] == a[it + 1])
                it++;
            it++;
        }
    }

    if (good)
        printf("Possible\n");
    else
        printf("Impossible\n");


	return 0;
}


