#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int n;
int a[N];
ll add[N];
ll sum;

ll solve(ll x) {
    ll ans = 0;
    ll sum = x;
    for (int i = 1; i < n; ++i) {
        ll nsum = sum + a[i];
        if (sum < 0) {
            if (nsum <= 0) { // to 1
                ans += 1 - nsum;
                nsum = 1;
            }
        } else {
            if (nsum >= 0) { // to -1
                ans += nsum + 1;
                nsum = -1;
            }
        }
        sum = nsum;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0] == 0) {
        cout << min(solve(1), solve(-1)) + 1 << endl;
    } else {
        ll ans1 = solve(a[0]);
        ll ans2;
        if (a[0] > 0) {
            ans2 = solve(-1) + a[0] + 1;
        } else {
            ans2 = solve(1) + 1 - a[0];
        }
        cout << min(ans1, ans2) << endl;
    }
    return 0;
}
