#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int n;
V<int> a;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    cin >> n;
    a = V<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    int i = 0, j = 1;
    while (true) {
        if (i == n - 1 || a[i + 1] < j + 1) break;
        i++; j++;
    }
    int u1 = 0, u2 = 0;
    if (a[i] > j) {
        u1 = (a[i] - j) & 1;
    }
    while (i < n - 1 && a[i + 1] == j) {
        i++;
        u2 = 1 - u2;
    }
    if (u1 || u2) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}