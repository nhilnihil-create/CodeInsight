#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define vt vector
#define pq priority_queue
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)
// #define multicase
const int MOD = 1e9 + 7;
const int INF = 2e9;
const int N = 1e2 + 5;

int n;
int a[N];

void solve() {
    int T = 1;
  #ifdef multicase
    cin >> T;
  #endif
    for(int tc = 1; tc <= T; tc++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int ans = INF;
        for(int i = a[1]; i <= a[n]; i++) {
            int tot = 0;
            for(int j = 1; j <= n; j++) {
                int temp = a[j] - i;
                tot += temp * temp;
            }
            ans = min(ans, tot);
        }
        cout << ans << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
}