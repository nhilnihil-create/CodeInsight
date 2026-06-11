#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;
using boost::sort;
using boost::adaptors::reversed;

int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a);
    for (int i = 1; i < n; i++) a[i] += a[i - 1];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) if (a[i + 1] - a[i] > 2 * a[i]) ans = i + 1;
    cout << n - ans << endl;
}
