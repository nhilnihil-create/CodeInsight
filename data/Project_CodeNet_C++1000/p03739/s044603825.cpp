#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<ll> sum(N);
    sum[0] = a[0];
    for (int i = 1; i < N; i++) sum[i] = sum[i-1] + a[i];

    // 次の2通りの並べ方
    // - + - + ...
    // + - + - ...
    // 符号が異なるなら -x -> 1, x -> -1に変換
    // cum: 値の累計
    // cnt: 操作回数
    vector<ll> cum(2), cnt(2);
    for (int i = 0; i < N; i++) {
        int i1 = i % 2, i2 = (i + 1) % 2;
        if (sum[i] + cum[i1] <= 0) {
            ll d = abs(sum[i] + cum[i1]) + 1;
            cnt[i1] += d;
            cum[i1] += d;
        }
        if (sum[i] + cum[i2] >= 0) {
            ll d = abs(sum[i] + cum[i2]) + 1;
            cnt[i2] += d;
            cum[i2] -= d;
        }
    }
    cout << min(cnt[0], cnt[1]) << '\n';
}
