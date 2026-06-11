#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

ll nCr(int n, int r) {
    ll num = 1;
    for (int i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

// 値自体を求めることは簡単だけど、数え上げが面倒そう。
// 値の求め方：基本的に使うv[i]が少ないほど最大値を出しやすい。
// さらに、平均値のタイが一位に定まらない条件は、
// あとは、使う数が異なる場合でもタイになる場合はどんなケースかと考えると、どの数選んだとしても選んだ組合せが同じになるケース。
// 例えば 10 10 10 5 5 とかで、 5 2 3 とかだと、2個選んでも3個選んでもavg:10になる。

// 0番目に大きい品物の数をg0とするとき、g0がAより多いときに A, A+1, ... (g0まで) でそれぞれの組み合わせ数をカウントして足す。
// 例：5 5 5 5 5 で A=3,B=5のとき、5C3 + 5c4 + 5c5 = 10 + 5 + 1 = 16 通り

// g0がAより小さいときは、A個選ぶケース以外では最大にならない。
// つまり、A個をどう取るかだけ考えれば良い。
// 10 1 1 5 5のケースで、A=4のときは、10 5 5 1 と取ればよいが、とり方としてどちらの1をとるかが考えられる。
// つまり、vの中でA番目に大きい値を見て、その値が何個あるかによって組み合わせ数が変わる。
// 15 25 10 30
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    map<ll, ll> cnt;
    rep(i, n) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    sort(v.begin(), v.end(), greater<ll>());
    long double ans = 0;
    rep(i, a) ans += v[i];
    ans /= a;

    ll c = 0, ath = v[a-1];
    if (ath == v.front()) {
        for(int i = a; i <= min(b, cnt[ath]); i++)
            c += nCr(cnt[ath], i);
    } else {
        int start_idx = lower_bound(v.begin(), v.end(), ath, greater<ll>()) - v.begin();
        int end_idx = upper_bound(v.begin(), v.end(), ath, greater<ll>()) - v.begin();
        c = nCr(end_idx - start_idx, a - start_idx);
    }

    cout << fixed << setprecision(10) << ans << "\n" << c << endl;
    return 0;
}