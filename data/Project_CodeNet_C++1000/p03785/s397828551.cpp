#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    for (auto &x : T) cin >> x;
    sort(T.begin(), T.end());

    int lim = T.at(0) + K;
    int c = 0;
    int ans = 1;
    for (int i = 0; i < N; ++i) {
        if (T.at(i) <= lim && c < C) {
            c++;
        } else {
            ans++;
            c = 1;
            lim = T.at(i) + K;
        }
    }

    cout << ans << endl;

    return 0;
}