#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e5 + 10;

int n;
int a[nmax];

int get_gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

bool solve() {
    int even = 0, odd = 0;
    for (int i = 1; i <= n; ++i)
        (a[i] & 1) ? odd++ : even++;

    if (even&1) return 1;
    if (odd > 1) return 0;

    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) return 0;
        if (a[i]&1) a[i]--;
    }

    int gcd = a[1];
    for (int i = 2; i <= n; ++i)
        gcd = get_gcd(gcd, a[i]);
    for (int i = 1; i <= n; ++i)
        a[i] /= gcd;
    return solve() ^ 1;
}

int main()
{
   // freopen("input","r",stdin);
    //freopen("output","w",stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    if (solve()) printf("First\n");
    else printf("Second\n");

    return 0;
}
