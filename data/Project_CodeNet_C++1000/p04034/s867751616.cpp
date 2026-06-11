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

const int INF = 1e18 + 100;
const int MOD1 = 998244353;
const int MOD = 1e9 + 7;
const int N = 10001;
const int nul = 0;
const int SIZE = 1e6 * 3;


signed main() {
#ifdef parasha
    freopen("A.in.txt", "r", stdin);
#endif // parasha
    fast;
    int n, m;
    cin >> n >> m;
    vector<int> smth(n, 0), cnt(n, 1);
    smth[0] = 1;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (smth[x]) {
            //cout << y << endl;
            smth[y] = 1;
        }
        cnt[x]--; cnt[y]++;
        if (cnt[x] == 0) smth[x] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        //cout << smth[i] << " ";
        ans += smth[i];
    }
    //cout << endl;
    cout << ans << endl;
}
