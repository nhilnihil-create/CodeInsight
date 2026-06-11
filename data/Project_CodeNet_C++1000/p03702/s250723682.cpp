#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5 + 10;
ll h[N], x[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, a, b, c;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    c = a - b;
    ll st = 0, en = 1000 * 1000 * 1000, ans = n;
    while (st <= en) {
        ll mid = (st + en) / 2;
        for (int i = 0; i < n; i++)
            x[i] = max(h[i] - mid * b, 0LL);
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += (x[i] + c - 1) / c;
        if (sum <= mid) {
            ans = mid;
            en = mid - 1;
        }
        else
            st = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}
