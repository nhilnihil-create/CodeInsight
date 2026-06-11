
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2010;
int n, m;
int a[N], b[N], c[N];
ll d1, d2;
vector<ll> d(N, -0x3f3f3f3f3f3f3f3f);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        --a[i];
        --b[i];
    }
    d[0] = 0;
    for (int i = 0; i < n * 2; ++i) {
        for (int j = 0; j < m; ++j) {
            d[b[j]] = max(d[b[j]], d[a[j]] + c[j]);
        }
        if (i == n - 1)
            d1 = d[n - 1];
        else if (i == n * 2 - 1)
            d2 = d[n - 1];
    }
    if (d1 == d2)
        cout << d1 << endl;
    else
        cout << "inf" << endl;

    return 0;
}

