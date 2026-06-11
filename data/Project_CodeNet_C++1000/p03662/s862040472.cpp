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
#include <bitset>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using G = vector<vector<int>>;

void dfs(const int s, int c, const G& g, vector<int>& d)
{
    d[s] = c;

    for(const auto& t : g[s]) {
        if (d[t] == -1) {
            dfs(t, c + 1, g, d);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    G g(n);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    vector<int> d1(n, -1);
    vector<int> dn(n, -1);

    dfs(0, 0, g, d1);
    dfs(n-1, 0, g, dn);

    int f = 0;
    int s = 0;

    for (int i = 0; i < n; ++i) {
        if (d1[i] <= dn[i]) {
            ++f;
        } else {
            ++s;
        }
    }

    if (f > s) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }

    return 0;
}
