#include <cstdio>
#include <algorithm>

using namespace std;

#define long long long

const long MAXA = 1e16 + 1000;

long k, c[50];

bool Try(long n)
{
    long lo = (k - n) / (n + 1) + 1;
    long excess = k - lo * n;
    for (int i = 0; i < n; ++i)
    {
        c[i] = lo;
        long add = min(excess, (MAXA + k - n + 1) / (n + 1) - c[i]);
        c[i] += add;
        excess -= add;
    }
    return excess == 0;
}

int main()
{
    scanf("%lld", &k);
    if (k == 0)
    {
        printf("2\n1 1");
        return 0;
    }
    for (long i = 2; i <= 50; ++i)
        if (Try(i))
        {
            printf("%lld\n", i);
            for (int j = 0; j < i; ++j) printf("%lld ", i - 1 + (i + 1) * c[j] - k);
            break;
        }
    return 0;
}
