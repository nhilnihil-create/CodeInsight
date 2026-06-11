/*
  Contest 073
  B - Theater
  Rakesh Kumar --> 11/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::vector<std::pair<int, int>> log;
    while (n--) {
        int s = 0, e = 0;
        std::cin >> s >> e;
        log.emplace_back(std::make_pair(s, e));
    }

    std::sort(log.begin(), log.end(), [](const std::pair<int, int>& s,
                                         const std::pair<int, int>& e) {
                                          return s.second < e.second;
                                      });
    int chal_chitra_seats = 0;
    std::pair<int, int> p = log[0];
    for (std::size_t i = 1; i < log.size(); ++i) {
        if (log[i].first <= p.second) {
            p = std::make_pair(p.first, log[i].second);
        } else {
            chal_chitra_seats += p.second - p.first + 1;
            p = log[i];
        }
    }
    chal_chitra_seats += p.second - p.first + 1;
    std::cout << chal_chitra_seats << std::endl;

    return 0;
}
