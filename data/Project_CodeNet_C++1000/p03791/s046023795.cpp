/*
ID: y1197771
PROG: test
LANG: C++
*/
#include<bits/stdc++.h>
#define pb push_back
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define dbg(x) cout << #x << " at line " << __LINE__ << " is: " << x << endl
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int fac[maxn];
int a[maxn];
int n;
int c[maxn];
int cnt[maxn];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if(n == 2) {
        cout << 2 << endl;
        return;
    }
    for (int i = 2; i < n; i++) {
        int t = (i - c[i - 1]) * 2 - 1;
        if(a[i - 1] >= t) {
            c[i] = c[i - 1];
        } else {
            //c[i] = (a[i - 1] + 2) / 2 - i;
            int t = i;
            while(t * 2 - 1 > a[i - 1]) t--;
            c[i] = i - t;
        }
        //cout << i << " " << c[i] << endl;
        cnt[c[i] ]++;
    }
    for (int i = n - 1; i >= 1; i--) cnt[i] += cnt[i + 1];
    ll res = 1;
    //cout << "asd" << endl;
    for (int i = n; i >= 1; i--) {
            //cout << i << " " << n - i + 1 << " " << cnt[n - i + 1] << endl;
        res = res * (i - cnt[n - i + 1]) % mod;
    }
    cout << res << endl;
}
int main() {
   // freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
