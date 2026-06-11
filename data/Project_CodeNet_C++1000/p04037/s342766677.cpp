#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN];
int32_t main () {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    a[n] = 0;
    a[n + 1] = 1e9 + 10;
    sort(a, a + n + 2);
    reverse(a, a + n + 2);
    int now = 0;
    while (a[now] > now)
        ++now;
    bool k = false;
    if (a[now] != now && ((a[now - 1] + now - 1) & 1))
        k = true;
    if (a[now] == now - 1 || a[now] == now) {
        while (a[now] == a[now + 1])    
            ++now;
        if ((now + a[now]) & 1)
            k = true;
    }
    cout << (k ? "First" : "Second");
    return 0;
}