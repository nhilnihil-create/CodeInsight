#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> S;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        S.emplace_back(x, y);
    }

    vector<pair<int,int>> C;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        C.emplace_back(x, y);
    }

    auto dis = [&](long long x1, long long y1, long long x2, long long y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    };

    for (int i = 0; i < n; ++i) {
        pair<long long, int> best{1LL << 60, 0};
        for (int j = 0; j < m; ++j) {
            auto d = dis(S[i].first, S[i].second, C[j].first, C[j].second);
            best = min(best, make_pair(d, j));
        }

        cout << best.second + 1 << '\n';
    }


    return 0;
}