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

    int len, n;
    scanf("%d%d", &len, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int odd = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2)
        {
            swap(a[i], a[odd]);
            odd++;
        }

    if (odd > 2)
    {
        printf("Impossible\n");
        return 0;
    }

    int sum = 0;
    sort(a + odd, a + n);
    if (odd == 2)
        rotate(a + 1, a + 2, a + n);

    vector <int> b;
    if (a[0] != 1)
    {
        b.push_back(a[0] - 1);
        sum += a[0] - 1;
    }
    for (int i = 1; i < n - 1; i++)
    {
        b.push_back(a[i]);
        sum += a[i];
    }
    if (sum != len)
        b.push_back(len - sum);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n%d\n", (int) b.size());
    for (int x : b)
        printf("%d ", x);
    printf("\n");



	return 0;
}


