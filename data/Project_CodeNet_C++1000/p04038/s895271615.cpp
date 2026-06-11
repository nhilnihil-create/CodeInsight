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

const int MOD = (int) 1e9 + 7;

void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}


const int N = 2005;
const int X = N * N;

int fact[X], ri[X], rfact[X];

void init()
{
    ri[1] = 1;
    fact[0] = 1;
    rfact[0] = 1;

    for (int i = 1; i < X; i++)
    {
        if (i != 1)
            ri[i] = sub(0, mul(ri[MOD % i], MOD / i));
        fact[i] = mul(fact[i - 1], i);
        rfact[i] = mul(rfact[i - 1], ri[i]);
    }
}

int C(int n, int k)
{
    //eprintf("get C : %d %d\n", n, k);
    if (k < 0 || k > n)
        return 0;
    return mul(fact[n], mul(rfact[k],rfact[n - k]));
}

int dp[N][N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    init();

    int n, k;
    scanf("%d%d", &n, &k);

    if (k == 1)
    {
        printf("1\n");
        return 0;
    }

    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
        {
            int cur = dp[i][j];
      //      eprintf("i = %d, j = %d : %d\n", i, j, dp[i][j]);

            if (i < n)
            {
                int cnt = (i + 1) * (k - 1) + j;
                int nx = mul(cur, C(cnt - 1, k - 2));
                sadd(dp[i + 1][j], nx);
            }
            if (j < i)
            {
                sadd(dp[i][j + 1], cur);
            }
        }
    printf("%d\n", mul(dp[n][n], fact[n]));



	return 0;
}


