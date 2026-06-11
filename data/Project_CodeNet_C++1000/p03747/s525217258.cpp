#include <bits/stdc++.h>
using i64 = long long;

struct S {
    int x, w, i;
    S(int x, int w, int i) : x(x), w(w), i(i) {}
};

int main() {
    i64 n, l, t;
    std::cin >> n >> l >> t;
    std::vector<S> vs;
    i64 cnt[] { 0, 0, 0 };
    for (int i = 0; i < n; i++) {
        int x, w;
        std::cin >> x >> w;
        vs.emplace_back(x, w, i);
        cnt[w]++;
    }

    const auto f = vs.front();
    i64 bump = t / l * 2 * (f.w == 1 ? cnt[2] : cnt[1]),
        rem = t % l;
    for (int i = 1; i < n; i++) {
        if (f.w == vs[i].w) continue;
        auto dist = f.w == 1 ? vs[i].x - f.x : f.x + l - vs[i].x;
        if (dist < rem * 2 || (f.w == 2 && dist == rem * 2)) bump++;
        if (dist + l < rem * 2 || (f.w == 2 && dist + l == rem * 2)) bump++;
    }

    auto s = f.w == 1 ? bump % n : (n - bump % n) % n;
    std::vector<int> pos;
    for (const auto &e : vs) {
        if (e.w == 1) pos.push_back((e.x + rem) % l);
        else pos.push_back((e.x - rem + l) % l);
    }
    int sp = pos.front();
    std::sort(pos.begin(), pos.end());

    auto m = std::lower_bound(pos.begin(), pos.end(), sp) - pos.begin();
    std::vector<int> ret(n);
    for (int j = 0; j < n; j++) {
        ret[vs[(j + s) % n].i] = pos[(j + m) % n];
    }

    for (auto e : ret) std::cout << e << std::endl;

    return 0;
}
