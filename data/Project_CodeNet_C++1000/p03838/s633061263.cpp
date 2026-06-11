#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int ans = INT_MAX;
    if (x <= y) ans = min(ans, y - x);
    if (-x <= y) ans = min(ans, y + x + 1);
    if (x <= -y) ans = min(ans, -y - x + 1);
    if (-x <= -y) ans = min(ans, -y + x + 2);
    printf("%d\n", ans);
    return 0;
}