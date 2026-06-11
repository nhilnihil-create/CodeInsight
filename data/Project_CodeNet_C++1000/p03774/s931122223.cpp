/*
  B - Checkpoints
  Contest 057
  Rakesh Kumar --> 20/08/2020
 */

#include <bits/stdc++.h>

using ll = long long int;

struct Point {
    Point(ll a, ll b) : x(a), y(b) {}
    ll x = 0;
    ll y = 0;
};

inline ll dist(const std::shared_ptr<Point>& a,
               const std::shared_ptr<Point>& b) {
    return std::abs(a->x - b->x) + std::abs(a->y - b->y);
}

inline int pos(const std::shared_ptr<Point>& pos,
               const std::vector<std::shared_ptr<Point>>& checkpoints) {
    ll min = dist(pos, checkpoints[0]);
    int p = 1;
    for (std::size_t i = 1; i < checkpoints.size(); ++i) {
        const ll d = dist(pos, checkpoints[i]);
        if (d < min) {
            p = i + 1;
            min = d;
        }
    }
    return p;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::shared_ptr<Point>> students;
    while (n--) {
        ll a = 0, b = 0;
        std::cin >> a >> b;
        students.emplace_back(new Point(a, b));
    }
    std::vector<std::shared_ptr<Point>> checkpoints;
    while (m--) {
        ll a = 0, b = 0;
        std::cin >> a >> b;
        checkpoints.emplace_back(new Point(a, b));
    }

    for (const std::shared_ptr<Point>& p : students)
        std::cout << pos(p, checkpoints) << std::endl;

    return 0;
}
