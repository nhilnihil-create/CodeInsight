#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 123456;

int n;
ll a[N];

int main() {
    ll single = 0;
    ll sm = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        single += i + 1;
        scanf("%lld", &a[i]);
        sm += a[i];
    }

    if (n == 1) {
        puts("YES");
        return 0;
    }

    if (sm % single != 0) {
        puts("NO");
        return 0;
    }

    ll cnt = sm / single;
    ll tot = 0;

    for (int i = 0; i < n; i++) {
        ll d = a[(i + 1) % n] - a[i];
        if ((cnt - d) % n != 0 || (cnt - d) / n > cnt || (cnt - d) / n < 0) {
            puts("NO");
            return 0;
        }
        tot += (cnt - d) / n;
    }

    puts("YES");
}
