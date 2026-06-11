#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma optimize("JARU SOSISONI")

using namespace std;

#define int long long
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define geometry cout.setf(ios::fixed); cout.precision(15);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 100;
const int MOD1 = 998244353;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int nul = 0;
const int SIZE = 1e6 * 3;



signed main() {
#ifdef parasha
    freopen("A.in", "r", stdin);
#endif // parasha
    fast;
    int q;
    q = 1;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
        int sum = 0;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            a[i] += sum;
            int res = (b[i] - a[i] % b[i]) % b[i];
            ans += res;
            sum += res;
            //cout << res << " " << endl;
        }
        cout << ans << endl;
    }
}










