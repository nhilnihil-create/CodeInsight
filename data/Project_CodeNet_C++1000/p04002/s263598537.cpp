#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cstring>

using namespace std;

constexpr long long mod = 1000000007;
constexpr double eps = 0.0000000001;

typedef long long ll;
typedef long long unsigned ull;

int main() {
    int n, h, w;
    ll c[10];
    cin >> h >> w >> n;
    for (int i = 0; i < 10; i++) c[i] = 0;
    c[0] = (ll)(h - 2) * (w - 2);
    vector<pair<int, int>> m(n);
    set<pair<int, int>> s;
    for (auto &e:m) {
        cin >> e.first >> e.second;
        for (int i = -2; i < 3; i++)
            for (int j = -2; j < 3; j++)
                if (e.first + i > 0 && e.first + i <= h && e.second + j > 0 && e.second + j < +w)
                    s.insert(make_pair(e.first + i, e.second + j));
    }
    sort(m.begin(), m.end());
    for (auto &e:s) {
        if (e.first + 2 > h || e.second + 2 > w) continue;
        int d = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (binary_search(m.begin(), m.end(), make_pair(e.first + i, e.second + j))) d++;
            }
        }
        c[d]++;
        c[0]--;
    }
    for(int i = 0;i < 10;i++) cout << c[i] << endl;
}