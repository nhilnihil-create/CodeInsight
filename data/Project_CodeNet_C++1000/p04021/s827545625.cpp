#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    pair<int, int> p[n];

    for (int i = 0; i < n; i++)
        cin >> p[i].first, p[i].second = i;

    sort(p, p + n);
    for (int i = 0; i < n; i++)
        if (i % 2 != p[i].second % 2)
            ans++;

    cout << ans / 2 << "\n";
}