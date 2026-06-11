#include <bits/stdc++.h>
#define int long long
#define sz size()
#define all(s) s.begin(), s.end()
#define mkp make_pair
#define pb push_back


using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 12;

int h[maxn];
int a, b, n;

void Speed() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool check(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; ++ i) {
        int cur = h[i] - b * x;
        if (cur > 0) {
            if (cur % (a - b))
                cnt += cur / (a - b) + 1;
            else
                cnt += cur / (a - b);
        }
    }
    return (cnt <= x);
}

void solve() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++ i) {
        cin >> h[i];
    }
    int l = 0;
    int r = mod;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
}

main() {
    Speed();
    solve();
}
