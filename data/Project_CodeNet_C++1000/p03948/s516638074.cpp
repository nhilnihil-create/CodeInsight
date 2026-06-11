#include <bits/stdc++.h>
using namespace std;

int n, t, x, mn=2e9, a1, a2;

int main() {
    scanf("%d%d", &n, &t);
    while (n--) {
        scanf("%d", &x);
        if (x - mn > a1) a1 = x-mn, a2 = 1;
        else if (x - mn == a1) a2++;
        mn = min(mn, x);
    }
    printf("%d\n", a2);
    return 0;
}
