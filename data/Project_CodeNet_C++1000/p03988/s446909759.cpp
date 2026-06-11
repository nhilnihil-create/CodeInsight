#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
  
typedef long long ll;
const int N = 100010;
const ll mod = 1e9 + 7;

int a[N], b[N];

int main()
{
    int n, mx = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ++b[a[i]];
        mx = max(mx, a[i]);
    }
    int p = mx / 2;
    if ((mx & 1) == 0) --b[p];
    for (int i = p + 1; i <= mx; ++i) {
        --b[i], --b[i];
        if (b[i] < 0) {
            puts("Impossible");
            return 0;
        }
    }
    for (int i = 0; i <= p + (mx & 1); ++i) {
        if (b[i]) {
            puts("Impossible");
            return 0;
        }
    }
    puts("Possible");
    return 0;
}