#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int maxn = 2e5 + 10;
int a[maxn];
bool vis[maxn];

int main() {
    __;
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
        return 0;
    }
    if (x <= n) {
        a[n] = x;
        a[n - 1] = x - 1;
        vis[x - 1] = 1;
        vis[x] = 1;
    } else {
        a[n - 1] = x;
        a[n] = x + 1;
        vis[x] = 1;
        vis[x + 1] = 1;
    }
    int p = 1;
    for (int i = 1; i < n - 1; ++i) {
        while (vis[p] == 1)++p;
        a[i] = p;
        vis[p] = 1;
    }
    for (int i = n + 1; i < n + n; ++i) {
        while (vis[p] == 1)++p;
        a[i] = p;
        vis[p] = 1;
    }
    cout << "Yes" << '\n';
    for (int i = 1; i < n + n; ++i) { cout << a[i] << '\n'; }
    return 0;
}