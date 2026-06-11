#include <bits/stdc++.h>
using namespace std;

int n, a, b;
long long ways, v[55], C[55][55];
long double ans;
map<long long, int> f, take;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        f[v[i]]++;
    }

    sort(v, v+n, greater<long long>());
    for (int i = 0; i < a; i++) {
        ans += v[i];
        take[v[i]]++;
    }

    cout << setprecision(10) << fixed << ans / a << '\n';

    C[0][0] = 1;
    for (int i = 1; i <= 50; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            }
            else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    if (v[0] == v[a-1]) {
        for (int i = a; i <= b; i++) {
            ways += C[f[v[0]]][i];
        }
    }
    else {
        ways = C[f[v[a-1]]][take[v[a-1]]];
    }

    cout << ways << '\n';

    return 0;
}