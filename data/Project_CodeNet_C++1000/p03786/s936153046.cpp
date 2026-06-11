#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a[100000];
    long long total = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
    sort(a, a + n, greater<int>());
    int colors = 1;
    for (int i = 1; i < n; ++i) {
        total -= a[i - 1];
        if (a[i - 1] > total * 2) break;
        ++colors;
    }
    cout << colors << '\n';
    return 0;
}
