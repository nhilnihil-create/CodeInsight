#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N, C, K;
    cin >> N >> C >> K;
    vector<ll> T(N);

    rep(i, N) { cin >> T[i]; }
    sort(all(T));

    vector<bool> ride(N, false);

    ll ans = 0;
    rep(i, N) {
        if (!ride[i]) {
            ll limit = T[i] + K;
            ll cnt = 0;
            while (T[i] <= limit && cnt < C && i < N) {
                ride[i] = true;
                i++;
                cnt++;
            }
            i--;
            ans++;
        }
    }

    cout << ans << endl;
}