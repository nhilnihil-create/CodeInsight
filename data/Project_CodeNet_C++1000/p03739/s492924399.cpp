#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    ll prev = -INF, sum = 0, cnt = 0, ans = INF;
    // 偶数番目が正
    rep(i, N) {
        cin >> a[i];
        sum += a[i];
        if (prev <= 0 && sum <= 0) {
            cnt += (1 - sum);
            sum = 1;
        } else if (prev >= 0 && sum >= 0) {
            cnt += (abs(-1 - sum));
            sum = -1;
        }
        prev = sum;
    }

    ans = min(ans, cnt);

    prev = INF, sum = 0, cnt = 0;
    //偶数番目が負
    rep(i, N) {
        sum += a[i];
        if (prev <= 0 && sum <= 0) {
            cnt += (1 - sum);
            sum = 1;
        } else if (prev >= 0 && sum >= 0) {
            cnt += (abs(-1 - sum));
            sum = -1;
        }
        prev = sum;
    }

    ans = min(ans, cnt);

    cout << ans << endl;
}