#include <bits/stdc++.h>
using namespace std;

long long N;

int main() {

    scanf("%lld", &N);

    long long lo = 1, hi = 1e7, mid, ans;
    while (lo <= hi) {
        mid = (lo + hi) / 2;

        if (mid * (mid + 1) / 2 >= N) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    while (N > ans) {
        printf("%lld\n", ans);
        N -= ans;
        ans--;
    }

    if (N) {
        printf("%lld\n", N);
    }

    return 0;
}