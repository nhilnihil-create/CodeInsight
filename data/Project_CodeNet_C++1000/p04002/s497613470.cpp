#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;

map <iiii, int> mm;
int h, w, n, ans[10];
vector <ii> v;

bool inside (int x, int y) {
    return (x >= 1 && x <= h && y >= 1 && y <= w);
}

signed main(){
    scanf("%lld %lld %lld", &h, &w, &n);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%lld %lld", &x, &y);
        v.push_back(make_pair(x, y));
    }

    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < v.size(); i++) {
        for (int dx = -2; dx <= 0; dx++) {
            for (int dy = -2; dy <= 0; dy++) {
                int start_x = v[i].first + dx;
                int start_y = v[i].second + dy;
                int end_x = start_x + 2;
                int end_y = start_y + 2;

                if (!inside(start_x, start_y) || !inside(end_x, end_y)) continue;
                mm[make_pair(make_pair(start_x, start_y), make_pair(end_x, end_y))]++;
            }
        }
    }

    for (map <iiii, int>::iterator it = mm.begin(); it != mm.end(); it++) ans[it->second]++;
    int sum = 0;
    for (int i = 1; i <= 9; i++) sum += ans[i];
    ans[0] = (h - 2) * (w - 2) - sum;
    for (int i = 0; i < 10; i++) printf("%lld\n", ans[i]);
    return 0;
}