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
int a[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int lst = -1;
    for (int i = 0; i < n - 1; i++)
        if (a[i] + a[i + 1] >= l)
            lst = i;

    if (lst == -1)
    {
        printf("Impossible\n");
        return 0;
    }

    printf("Possible\n");
    for (int i = 0; i < lst; i++)
        printf("%d\n", i + 1);
    for (int i = n - 2; i >= lst + 1; i--)
        printf("%d\n", i + 1);
    printf("%d\n", lst + 1);


	return 0;
}


