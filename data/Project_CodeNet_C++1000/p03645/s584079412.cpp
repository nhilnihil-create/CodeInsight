#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for (auto i : to[0]) {
        for (auto j : to[i]) {
            if (j == n - 1) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
