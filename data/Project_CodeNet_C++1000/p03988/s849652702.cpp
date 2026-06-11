#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, d[N], cnt[N], L, hL;
void check() {
    for (int i = 1; i < hL; i++)
        if (cnt[i]) {
            puts("Impossible");
            return;
        }
    for (int i = hL + 1; i < L; i++)
        if (cnt[i] < 2) {
            puts("Impossible");
            return;
        }
    if (L & 1) {
        if (cnt[hL] != 2) {
            puts("Impossible");
            return;
        }
    } else {
        if (cnt[hL] != 1) {
            puts("Impossible");
            return;
        }
    }
    puts("Possible");
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        cnt[d[i]]++;
        L = max(d[i], L);
    }
    hL = (L + 1) / 2;
    check();
    return 0;
}