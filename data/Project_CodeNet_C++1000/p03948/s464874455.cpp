#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

llong n, t;
llong a[100005];
llong ans = 1;

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    llong max_s = 0;
    llong minv = a[0];
    for (int i = 1; i < n; i++) {
        llong s = a[i] - minv;

        if (max_s < s) {
            max_s = s;
            ans = 1;
        }
        else if (max_s == s) {
            ans++;
        }

        minv = min(a[i], minv);
    }

    cout << ans << endl;

    return 0;
}
