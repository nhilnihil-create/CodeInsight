#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

ll binomial(int n, int r) {
    ll res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= n - r + i;
        res /= i;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    sort(v.rbegin(), v.rend());
    int mcnt = 1;
    ll msum = 0, sum = 0, cnt = 0;
    for (int i = 0; i < N; ++i) {
        sum += v[i];
        if (i + 1 < A || i + 1 > B)
            continue;
        ll tmp1 = (i + 1) * msum, tmp2 = mcnt * sum;
        if (tmp1 <= tmp2) {
            auto itr1 = lower_bound(v.rbegin(), v.rend(), v[i]);
            auto itr2 = upper_bound(v.rbegin(), v.rend(), v[i]);
            int n = itr2 - itr1;
            int r = itr2 - v.rbegin() - (N - i - 1);
            if (tmp1 < tmp2)
                cnt = binomial(n, r);
            else
                cnt += binomial(n, r);
            mcnt = i + 1;
            msum = sum;
        }
    }

    printf("%.6lf\n", (double)msum / mcnt);
    printf("%lld\n", cnt);
    return 0;
}
