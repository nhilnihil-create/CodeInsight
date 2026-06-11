#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define l first
#define r second

using namespace std;

const int maxn = 2e5 + 1;

int a[maxn], b[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int oc = 0;
    for (int i = 0; i < n; i++)
        oc += (a[i] % 2);
    cout << (oc % 2 ? "NO" : "YES");
    return 0;
}
