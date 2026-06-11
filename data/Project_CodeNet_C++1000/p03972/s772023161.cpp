#include <bits/stdc++.h>

using namespace std;

char s[100005];
int main() {
    long long ans = 0;
    int w, h;
    scanf("%d %d", &w, &h);
    vector<pair<int, string>> e;
    for (int i = 0; i < w; ++i) {
        int a;
        scanf("%d", &a);
        e.push_back({a, "W"});
    }

    for (int i = 0; i < h; ++i) {
        int a;
        scanf("%d", &a);
        e.push_back({a, "H"});
    }

    sort(e.begin(), e.end());

    int cnt_w = w + 1;
    int cnt_h = h + 1;
    for (int i = 0; i < w + h; ++i) {
        auto p = e[i];
        if (p.second == "W") {
            ans += 1LL * cnt_h * p.first;
            cnt_w--;
        }
        else {
            ans += 1LL * cnt_w * p.first;
            cnt_h--;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
