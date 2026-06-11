#include <bits/stdc++.h>

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::vector<long long> a(n), cnt(m + 2), from(m + 1);
    std::map<long long, std::map<long long, long long>> to;
    std::cin >> a[0];
    for (int i = 1; i < n; i++) {
        from[a[i - 1]]++;

        std::cin >> a[i];
        to[a[i]][a[i - 1]]++;
        cnt[a[i - 1] + 1]++;
        cnt[a[i] + 1]--;
        if (a[i] < a[i - 1]) {
            cnt[m + 1]--;
            cnt[0]++;
        }
    }

    for (int i = 1; i < m + 2; i++) {
        cnt[i] += cnt[i - 1];
    }

    auto p(a);
    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(), p.end()), p.end());

    auto ret = 0ll;
    for (int i = 1; i < n; i++) {
        if (a[i] == p[0]) {
            ret++;
        } else if (a[i - 1] > a[i]) {
            ret += a[i] - p[0] + 1;
        } else {
            ret += a[i] - a[i - 1];
        }
    }

  	auto curr = ret;
    for (int i = 1; i < p.size(); i++) {
        for (auto& el : to[p[i - 1]]) {
            curr += el.second * ((p[i - 1] - el.first + m) % m - 1);
        }
        curr -= (p[i] - p[i - 1]) * cnt[p[i]];
        curr += from[p[i - 1]];
        ret = std::min(curr, ret);
    }

    std::cout << ret << std::endl;

    return 0;
}