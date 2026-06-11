#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int n; ll L; scanf("%d %lld", &n, &L);
    ll a[n + 2];
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 1; i < n; i++) {
        if (a[i] + a[i + 1] >= L) {
            puts("Possible");
            vector <int> ans;
            for (int j = 1; j < i; j++) printf("%d\n", j);
            for (int j = n; j > i + 1; j--) printf("%d\n", j - 1);
            printf("%d\n", i);
            return 0;
        }
    }

    puts("Impossible");
}