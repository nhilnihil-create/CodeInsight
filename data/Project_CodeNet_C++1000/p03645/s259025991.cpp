#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};
constexpr int A_MAX = 200000;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<bool> c1(n, false), cn(n, false);
    for(int i=0;i<m;++i) {
        cin >> a >> b;
        --a; --b;
        if(a > b) swap(a, b);
        if(a == 0) {
            c1[b] = true;
        }
        if(b == n-1) {
            cn[a] = true;
        }
    }

    for(int i=0;i<n;++i) {
        if(c1[i] && cn[i]) {
            cout << "POSSIBLE\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
