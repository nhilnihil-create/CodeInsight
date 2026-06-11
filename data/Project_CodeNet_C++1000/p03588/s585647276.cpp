#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    auto max_it = max_element(p.begin(), p.end(), [](const auto& p1, const auto& p2) { return p1.first < p2.first; });

    int ans = max_it->first + max_it->second;

    cout << ans << endl;

    return 0;
}
