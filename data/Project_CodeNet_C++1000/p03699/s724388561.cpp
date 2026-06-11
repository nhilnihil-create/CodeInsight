#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)


void solve() {
    int n;
    cin >> n;
    vi v;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    sort(bn(v));
    int w = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 10 == 0) {
            w++;
        }
        if (w == v.size()) {
            cout << 0 << "\n";
            return;
        }
        if (sum % 10 == 0) {
            if ((sum - v[i]) % 10 != 0) {
                sum -= v[i];
            }
        } else {
            cout << sum << "\n";
            return;
        }
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i = 1;
    //cin >> t;
    while(t--) {
        //cout << "Case #" << i << ": ";
        solve();
        //i++;
    }
    return 0;
}
