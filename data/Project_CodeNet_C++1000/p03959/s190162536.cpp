#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

template<class T, class Compare = greater<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = less<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;
const llong MOD = (llong)(1e9) + 7;

llong n;
llong t[100005];
llong a[100005];

llong ti[100005];
llong ai[100005];

llong ans = 1;

int main() {

    cin >> n;
    for (llong i = 0; i < n; i++) cin >> t[i];
    for (llong i = 0; i < n; i++) cin >> a[i];

    for (llong i = 1; i < n; i++) {
        if (t[i] > t[i - 1]) ti[i] = t[i];
    }
    for (llong i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) ai[i] = a[i];
    }
    for (llong i = 0; i < n; i++) {
        if (a[i] < ti[i]) ans = 0;
        if (t[i] < ai[i]) ans = 0;
    }

    if (a[0] != t[n - 1]) ans = 0;

    for (llong i = 1; i < n - 1; i++) {
        if (t[i] == t[i - 1] && a[i] == a[i + 1]) {
            ans *= min(t[i], a[i]);
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
