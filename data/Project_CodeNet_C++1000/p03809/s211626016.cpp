#include <bits/stdc++.h>

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<std::set<long long>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b; a--; b--;
        g[a].insert(b);
        g[b].insert(a);
    }

    std::vector<std::deque<long long>> ch(n);
    std::vector<long long> p(n, -1);
    std::deque<long long> q2;
    q2.push_back(0);
    while (!q2.empty()) {
        auto curr = q2.front();
        for (auto to : g[curr]) {
            if (to == p[curr]) continue;
            ch[curr].push_back(to);
            p[to] = curr;
            q2.push_back(to);
        }
        q2.pop_front();
    }

    std::deque<long long> q;
    std::vector<bool> done(n, false);
    std::vector<long long> c(n), t(n);
    q.push_back(0);
    while (!q.empty()) {
        auto curr = q.back();
        if (ch[curr].empty()) {
            t[curr] = a[curr];
            q.pop_back();
        } else if (done[curr]) {
            if (ch[curr].size() == 1) {
                t[curr] = t[ch[curr][0]];
                if (t[curr] != a[curr]) {
                    std::cout << "NO" << std::endl;
                    return 0;
                }
                q.pop_back();
                continue;
            }
            // 2*c + t = sum_of_children_t
            // c + t = a_i
            auto s = std::accumulate(ch[curr].begin(), ch[curr].end(), 0ll, [&](auto init, auto k) {
                return init + t[k];
            });

            c[curr] = s - a[curr];
            t[curr] = a[curr] - c[curr];
            q.pop_back();
            if (c[curr] < 0 || t[curr] < 0 || t[curr] > a[curr] || c[curr] > a[curr]) {
                std::cout << "NO" << std::endl;
                return 0;
            }
            s += t[curr];
            if (std::any_of(ch[curr].begin(), ch[curr].end(), [&](auto el) { return 2 * t[el] > s; }) || 2 * t[curr] > s) {
                std::cout << "NO" << std::endl;
                return 0;
            }
        } else {
            for (auto el : ch[curr]) q.push_back(el);
            done[curr] = true;
        }
    }

    if (g[0].size() == 1) {
        std::cout << (t[0] == a[0] ? "YES" : "NO") << std::endl;
    } else {
        std::cout << (t[0] ? "NO" : "YES") << std::endl;
    }

    return 0;
}