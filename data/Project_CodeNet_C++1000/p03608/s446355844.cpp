#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


// 68 11 55 - rank 3
// 69 12 19 - rank 3
// 70 12 34 - rank 100
// 71 12 58 - rank 4
// 72 13 24 - rank 20
// 73 13 39

ull gcd(ull a, ull b) {
    while (b != 0) {
        auto na = a % b;
        a = b;
        b = na;
    }
    return a;
}


void oneCase() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> p(r);
    for (auto& el : p) {
        cin >> el;
        --el;
    }
    sort(p.begin(), p.end());
    vector<vector<ll>> dist(n, vector<ll>(n, 1e18));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int left = 0; left < n; ++left) {
            for (int right = 0; right < n; ++right) {
                dist[left][right] = min(dist[left][right], dist[left][k] + dist[k][right]);
            }
        }
    }

    ll best = 1e18;
    do {
        ll cur = 0;
        for (int i = 1; i < r; ++i) {
            cur += dist[p[i]][p[i - 1]];
        }
        best = min(best, cur);
    } while (std::next_permutation(p.begin(), p.end()));

    cout << best << "\n";
}


int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
       oneCase();
    }

    return 0;
}

ll fact(ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        res = (res * n) % mod;
        --n;
    }
    return res;
}
