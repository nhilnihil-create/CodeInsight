#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        puts(abs(x - y) <= 1 ? "Brown" : "Alice");
        return 0;
}

