#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

ll C(int n, int k)
{
    ll res = 1;
    for (int i = 0; i < k; i++) {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a, b; cin >> n >> a >> b;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<ll>());

    ll msum = 0; int mnum = 0; ll cnt = 0;
    for (int i = a; i <= b; i++) {
        ll total = accumulate(v.begin(), v.begin() + i, 0LL);
        if (total * mnum >= msum * i) {
            msum = total, mnum = i;
            ll tmp = C(
                count(v.begin(), v.end(), *(v.begin() + i - 1)),
                count(v.begin(), v.begin() + i, *(v.begin() + i - 1))
            );
            if (total * mnum == msum * i) cnt += tmp;
            else cnt = tmp;
        }
    }
    cout << fixed << setprecision(15) << (double)msum / mnum << endl; 
    cout << cnt << endl;
    return 0;
}
