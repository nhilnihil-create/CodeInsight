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

llong n;
llong a[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    llong ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[a[i]] == i) ans++;
    }

    cout << ans / 2 << endl;

    return 0;
}
