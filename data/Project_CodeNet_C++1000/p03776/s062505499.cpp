#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, a, b;
ll ans, sum;

ll combo(int n, int k) {
    int a = k, b = n - k;
    if (a < b)
        swap(a, b);
    int bi = 1;
    ll res = 1;
    for (int i = a + 1; i <= n; ++i) {
        while (1e18 / i < res && bi <= b) {
            res /= bi;
            ++bi;
        }
        res *= i;
    }
    for (; bi <= b; ++bi) {
        res /= bi;
    }
    return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a >> b;
    vector<ll> ar(n);
    rep(i, 0, n) {
        cin >> ar[i];
    }
    sort(all(ar), greater<ll>());
    rep(i, 0, a) {
        sum += ar[i];
    }
    cout << fixed << setprecision(6) << sum / (double)a << '\n';
    if (ar[a - 1] == ar[0]) {
        int tot = 0;
        rep(i, 0, n)
            if (ar[i] == ar[0])
                tot = i;
        ++tot;
        for (int i = a; i <= min(tot, b); ++i) {
            ans += combo(tot, i);
        }
    } else {
        // Count how many there are of ar[a - 1]. THen it's n Choose cnt
        int tot = 0, used = 0;
        rep(i, 0, n) {
            if (ar[i] == ar[a - 1]) {
                ++tot;
                if (i < a) ++used;
            }
        }
        ans = combo(tot, used);
    }
    cout << ans;
}
