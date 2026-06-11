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

    int n;
    cin >> n;

    vector<pair<int,int>> P;
    for (int i = 0; i < n; ++i) {
        int l = 0;
        int r = 0;
        cin >> l >> r;
        P.emplace_back(l, r);
    }
    sort(P.begin(), P.end());

    int res = 0;

    for (int i = 0; i < P.size(); ++i) {
        int l = P[i].first;
        int r = P[i].second;
        while (i + 1 < P.size() && r >= P[i + 1].first) {
            r = max(r, P[++i].second);
        }

        res += r - l + 1;
    }

    cout << res << '\n';

    return 0;
}