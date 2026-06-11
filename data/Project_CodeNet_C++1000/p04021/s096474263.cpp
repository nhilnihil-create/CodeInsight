#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n, ans = 0;
int a[maxn];
unordered_map < int, pair < int, int > > cnt;

signed main () {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i & 1)
            ++cnt[a[i]].first;
        else
            ++cnt[a[i]].second;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            if (cnt[a[i]].first)
                --cnt[a[i]].first;
            else
                ++ans;
        }
        else {
            if (cnt[a[i]].second)
                --cnt[a[i]].second;
            else
                ++ans;
        }
    }
    printf("%d\n", ans / 2);
}
