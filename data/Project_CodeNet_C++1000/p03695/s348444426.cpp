#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)
#define MX 1e5


void solve() {
    int n;
    cin >> n;
    vector<int> v(3201, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > 3199) {
            v[3200]++;
        } else if (a > 2799) {
            v[2800] = 1;
        } else if (a > 2399) {
            v[2400] = 1;
        } else if (a > 1999) {
            v[2000] = 1;
        } else if (a > 1599) {
            v[1600] = 1;
        } else if (a > 1199) {
            v[1200] = 1;
        } else if (a > 799) {
            v[800] = 1;
        } else if (a > 399) {
            v[400] = 1;
        } else if (a > 0 ) {
            v[0] = 1;
        }
    }
    int mx = accumulate(v.begin(), v.end(), 0);
    int cnt = 0;
    for (int i = 0; i < 3200; i+=400) {
        cnt += v[i];
    }
    if (v[3200] == n) {
        cout << cnt+1 << " " << n << "\n";
    } else {
        cout << cnt << " " << mx << "\n";
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
