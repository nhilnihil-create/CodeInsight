#include <cstdio>
#include <algorithm>
const int N = 205;
int n, v[N], a;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; ++i)
        scanf("%d", &v[i]);
    std::sort(v + 1, v + 2 * n + 1);
    for (int i = 1; i <= 2 * n; i += 2)
        a += v[i];
    printf("%d", a);
    return 0;
}