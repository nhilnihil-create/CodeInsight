#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

#define int long long

const int N = 3e5 + 7;
const int mod = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

int mul(int a, int b) {
    return (a * (ll) b) % mod;
}

int pw(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = mul(res, x);
            n--;
        }
        x = mul(x, x);
        n /= 2;
    }
    return res;
}

int fact[N];
int rfact[N];

int C(int n, int k) {
    return mul(fact[n], mul(rfact[n - k], rfact[k]));
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    rfact[N - 1] = pw(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        rfact[i] = mul(rfact[i + 1], i + 1);
    }
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int ans = 0;
    for (int j = b + 1; j <= w; j++) {
        int i = h - a;
        int cnt = C(i - 1 + j - 1, i - 1);
        int kek = C(h - i + w - j - 1, h - i - 1);
        add(ans, mul(cnt, kek));
    }
    cout << ans << '\n';
    return 0;
}
