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


const int N = 1005;
char s[N], t[N], str[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    scanf("%s%s", s, t);

    for (int i = n; i <= 2 * n; i++)
    {
        for (int j = 0; j < n; j++)
            str[j] = s[j];
        bool bad = false;
        for (int j = 0; j < n; j++)
            if (i - 1 - j < n && str[i - 1 - j] != t[n - 1 - j])
                bad = true;
        if (!bad)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    throw;




	return 0;
}


