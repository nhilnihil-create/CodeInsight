#include <stdio.h>
#include <cmath>

using i64 = long long;

int main() {
    i64 x, y; scanf("%lld%lld", &x, &y);

    if(std::abs(x - y) <= 1) printf("Brown\n");
    else printf("Alice\n");
    return 0;
}
