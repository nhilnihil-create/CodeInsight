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
using MinHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

llong n;
llong a[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        a[i + 1] += a[i];
    }

    llong ans = 1ll << 60ll;
    for (int i = 0; i < n - 1; i++) {
        llong x = a[i];
        llong y = a[n - 1] - a[i];

        ans = min(abs(x - y), ans);
    }

    cout << ans << endl;

    return 0;
}
