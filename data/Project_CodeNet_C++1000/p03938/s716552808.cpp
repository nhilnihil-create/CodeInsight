#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, step = 5e4;
    cin >> n;
    int a[n], b[n];

    a[0] = b[n - 1] = 1;
    for (int i = 1; i < n; i++)
        a[i] = a[i - 1] + step, b[n - i - 1] = a[i];

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        a[p - 1] += i;
    }

    for (int x : a)
        cout << x << ' ';
    cout << '\n';
    for (int x : b)
        cout << x << ' ';
    cout << '\n';

    return 0;
}