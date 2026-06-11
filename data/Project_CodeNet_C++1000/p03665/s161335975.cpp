#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong n, p;
llong a[55];
llong b[55];
llong acnt[2];
llong bcnt[2];

void dfs1(llong i, llong sum) {
    if (i >= n / 2) {
        acnt[sum % 2]++;
        return;
    }

    dfs1(i + 1, sum + a[i]);
    dfs1(i + 1, sum);
}

void dfs2(llong i, llong sum) {
    if (i >= n) {
        bcnt[sum % 2]++;
        return;
    }

    dfs2(i + 1, sum + a[i]);
    dfs2(i + 1, sum);
}

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dfs1(0, 0);
    dfs2(n / 2, 0);

    if (p == 0) {
        cout << acnt[0] * bcnt[0] + acnt[1] * bcnt[1] << endl;
    }
    else {
        cout << acnt[0] * bcnt[1] + acnt[1] * bcnt[0] << endl;
    }

    return 0;
}
