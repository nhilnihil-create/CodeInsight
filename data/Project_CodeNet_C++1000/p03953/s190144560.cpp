#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+5;

ll n, x[MAXN], m, k, a[MAXN];
ll p[MAXN], q[MAXN], d[MAXN];
bool vis[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    for (int i = 0; i < n-1; ++i)
        d[i] = x[i+1] - x[i];

    for (int i = 0; i < n-1; ++i)
        p[i] = i;

    cin >> m >> k;

    for (int i = 0; i < m; ++i) {
        int y; cin >> y;
        swap(p[y-2], p[y-1]);
    }

    for (int i = 0; i < n-1; ++i) {
        if (vis[i])
            continue;
        vector<int> v;
        int j = i;
        while (true) {
            v.push_back(j);
            j = p[j];
            if (j == i)
                break;
        }
        int s = v.size();
        for (int a = 0; a < s; ++a) {
            p[v[a]] = v[(a+k)%s];
            vis[v[a]] = 1;
        }
    }

    ll part = x[0];
    cout << x[0] << "\n";
    for (int i = 0; i < n-1; ++i) {
        part += d[p[i]];
        cout << part << "\n";
    }
}