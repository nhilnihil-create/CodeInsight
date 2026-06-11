#include <bits/stdc++.h>

int main()
{
    int a, b, c, d;
    int ans = 0;
    std::cin >> a >> b >> c >> d;
    for (int i = std::min(a, c); i <= std::max(b, d); ++i) {
        if (a <= i && i <= b && c <= i && i <= d) {
            ++ans;
        }
    }
    if (ans > 0) {
        --ans;
    }
    std::cout << ans << std::endl;
}