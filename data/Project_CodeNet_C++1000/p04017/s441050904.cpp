#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5 , M = 17;
int p[N][M];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int l , q;
    cin >> l >> q;

    p[0][0] = 0;
    for (int i = 0 ;i < n ; i++) {
        while (p[i][0] + 1 < n && a[p[i][0] + 1] - a[i] <= l)
            p[i][0]++;

        p[i + 1][0] = p[i][0];
    }

    for (int i = n - 1 ;i >= 0 ;i--)
        for (int j = 1 ;j < M ;j++)
            p[i][j] = p[p[i][j - 1]][j - 1];

    while (q--) {
        int a , b;
        cin >> a >> b;
        a-- , b--;

        if (a > b)
            swap(a , b);

        int ans = 0;
        for (int i = M - 1 ;i >= 0 ;i--) {
            if (p[a][i] < b) {
                ans += 1 << i;
                a = p[a][i];
            }
        }

        cout << ans + 1 << '\n';
    }
}