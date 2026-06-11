#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
// #include <bits/stdc++.h>


using namespace std;
typedef long long li;

struct BIT {
    int n;
    vector<li> bit;

    BIT(int _n): n(_n), bit(_n + 1) {}

    li sum(int i) {
        li s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, li x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    li n, k;
    cin >> n >> k;

    vector<li> xs(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i];
        xs[i] -= k;
    }

    priority_queue<pair<li, li>> q;
    q.emplace(0, -1);
    li acc = 0;
    for (int i = 0; i < n; ++i) {
        acc += xs[i];
        q.emplace(-acc, -(i + 2));
    }

    li ans = 0;
    BIT bit(n + 5);
    while (!q.empty()) {
        auto t = q.top(); q.pop();
        const li v = -t.first;
        const li i = -t.second;

        ans += bit.sum(i - 1);
        bit.add(i, 1);
    }

    cout << ans << endl;


    return 0;
}
