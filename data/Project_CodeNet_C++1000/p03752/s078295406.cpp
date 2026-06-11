#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define MAX 99999999999999

int main() {
    int N, K; cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    ll mx, cnt, cost, ans = MAX;
    rep(i, (1<<N)) {
        mx = cnt = cost = 0;
        rep(j, N) {
            if (mx < a[j]) {
                cnt++;
                mx = a[j];
            }
            else if ((i>>j)&1) {
                cost += mx - a[j] + 1;
                mx++;
                cnt++;
            }
        }
        if (cnt >= K) ans = min(ans, cost);
    }
    cout << ans << endl;
}
