#include <cstdio>
#include <algorithm>

int x, t;

void solve()
{
    printf("%d\n", std::max(0, x-t));
}

int main()
{
    scanf("%d%d", &x, &t);
    solve();
    return 0;
}