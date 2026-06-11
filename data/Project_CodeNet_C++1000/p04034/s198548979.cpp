#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<bool>check(N+1, false);
    vector<ll>box(N+1, 1);
    check[1] = true;

    for (int i = 0; i < M; i++) {
        ll x, y;
        cin >> x >> y;
        if (check[x]) {
            if (box[x]>=2) {
                check[y] = true;
            } else {
                check[x] = false;
                check[y] = true;
            }
        }
        box[x]--;
        box[y]++;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (check[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}
