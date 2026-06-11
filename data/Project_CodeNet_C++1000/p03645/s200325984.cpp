/*
  Contest 068
  C - Cat Snuke and a Voyage
  Rakesh Kumar --> 01/09/2020
*/

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, m = 0;
    std::cin >> n >> m;
    std::string r = "IMPOSSIBLE";
    std::unordered_map<int, bool> stop_overs;
    std::vector<int> stops;
    while (m--) {
        int s = 0, e = 0;
        std::cin >> s >> e;
        if (s == 1 && e == n)
            r = "POSSIBLE";
        else if (s == 1)
            stop_overs[e] = true;
        else if (e == n)
            stops.emplace_back(s);
    }
    if (r == "IMPOSSIBLE") {
        for (int s : stops) {
            if (stop_overs.find(s) != stop_overs.end()) {
                r = "POSSIBLE";
                break;
            }
        }
    }
    std::cout << r << std::endl;

    return 0;
}
