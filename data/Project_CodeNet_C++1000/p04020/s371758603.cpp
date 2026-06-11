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
const int MOD = 998244353;
const int MOD1 = 1e9 + 7;
const int N = 10100;
const int nul = 0;
const int SIZE = 1e6 * 3;



signed main() {
#ifdef parasha
    freopen("A.in", "r", stdin);
#endif // parasha
    fast;
    int ans = 0, n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    a.push_back(0);
    int sum = 0;
    for (int &i : a) {
        if (i == 0) {
            ans += sum / 2;
            sum = 0;
        } else sum += i;
    }
    cout << ans << endl;
}
