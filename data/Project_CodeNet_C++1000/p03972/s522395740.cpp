#include <bits/stdc++.h>
using i64 = long long;

int main() {
    i64 w, h;
    std::cin >> w >> h;
    std::vector<i64> p(w), q(h);
    for (int i = 0; i < w; i++) std::cin >> p[i];
    for (int i = 0; i < h; i++) std::cin >> q[i];

    std::sort(p.begin(), p.end());
    std::sort(q.begin(), q.end());

    i64 ret = 0;
    i64 x = 0, y = 0;
    for (int i = 0; i < h + w; i++) {
        if (y == h || (x < w && p[x] < q[y])) {
            ret += p[x] * (h - y + 1);
            x++;
        } else {
            ret += q[y] * (w - x + 1);
            y++;
        }
    }
    std::cout << ret << std::endl;

    return 0;
}
