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


const int N = (int) 2e4 + 100;

int a[N], b[N];
int p[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
        p[i]--;
    }
    
    for (int i = 0; i < n; i++)
    {
        a[i] = (i + 1) * N;
        b[i] = a[i];
    }
    reverse(b, b + n);

    for (int i = 0; i < n; i++)
        a[p[i]] += i;


    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");


	return 0;
}


