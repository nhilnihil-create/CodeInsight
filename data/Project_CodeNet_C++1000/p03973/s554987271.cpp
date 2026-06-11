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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int now = 1, ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == now) now++;
        else if (a[i] > now) {
            ans += (a[i] - 1) / now;
        }
        now = max(now, 2ll);
    }
    cout << ans << endl;

}










