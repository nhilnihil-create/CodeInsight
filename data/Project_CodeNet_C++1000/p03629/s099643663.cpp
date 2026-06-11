#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();

    std::vector<std::vector<int>> g(n, std::vector<int>(26));
    std::vector<int> nxt(26, -1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            g[i][j] = nxt[j];
        }
        nxt[s[i] - 'a'] = i;
    }

    // (len, to)
    std::vector<std::pair<int, int>> t(n, std::make_pair(1000000, -1));
    t[n - 1] = std::make_pair(2, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (g[i][j] < 0) {
                t[i] = std::min(t[i], std::make_pair(2, j));
            } else {
                t[i] = std::min(t[i], std::make_pair(t[g[i][j]].first + 1, j));
            }
        }
    }

    std::string ret = "";
    for (int i = 0; i < 26; i++) {
        if (nxt[i] < 0) {
            if (ret.size() != 1) ret = 'a' + i;
        } else {
            std::string tmp = "";
            int v = nxt[i];
            do {
                tmp += s[v];
                if (t[v].first > 2) {
                    v = g[v][t[v].second];
                } else {
                    tmp += ('a' + t[v].second);
                    break;
                }
            } while (true);
            if (ret.size() == 0) ret = tmp;
            else if (tmp.size() < ret.size() || (tmp.size() == ret.size() && tmp < ret)) ret = tmp;
        }
    }

    std::cout << ret << std::endl;

    return 0;
}
