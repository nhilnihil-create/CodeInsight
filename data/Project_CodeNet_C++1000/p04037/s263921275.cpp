#include <algorithm>
#include <cstdio>
#include <functional>

const int N = 100000;

int n, a[N];

bool win(int x, int y)
{
    while (x + 1 < n && y + 1 < a[x + 1]) {
        x ++, y ++;
    }
    int up = a[x] - y & 1;
    int rt = true;
    while (x + 1 < n && y < a[x + 1]) {
        x ++, rt ^= 1;
    }
    return !(up && rt);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    std::sort(a, a + n, std::greater<int>());
    puts(win(0, 0) ? "First" : "Second");
}
