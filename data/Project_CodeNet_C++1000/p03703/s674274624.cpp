#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

//1点更新,区間和
class SegmentTree {
public:
    SegmentTree(ll n) {
        n_ = (ll)pow(2, ceil(log2(n)));
        nodes_.resize(2 * n_ - 1, 0);
    }
    void addOne(ll x) {
        nodes_[x + n_ - 1]++;
        for (ll i = (x + n_ - 2) / 2; ; i = (i - 1) / 2) {
            nodes_[i] = nodes_[2 * i + 1] + nodes_[2 * i + 2];
            if (i == 0) {
                break;
            }
        }
    }

    ll getSum(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
        if (r < 0) {
            r = n_;
        }
        if (r <= a || b <= l) {
            return 0;
        }
        if (a <= l && r <= b) {
            return nodes_[k];
        }
        ll lv = getSum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = getSum(a, b, 2 * k + 2, (l + r) / 2, r);
        return lv + rv;
    }

private:
    //2のべき乗
    ll n_;
    vector<ll> nodes_;
};

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
        a[i] -= K;
    }

    vector<ll> b(N + 1, 0);
    for (ll i = 0; i < N; i++) {
        b[i + 1] = b[i] + a[i];
    }

    //座標圧縮
    map<ll, ll> mp;
    for (ll i = 0; i <= N; i++) {
        mp[b[i]] = 0;
    }
    ll count = 0;
    for (auto& itr : mp) {
        itr.second = count++;
    }

    vector<ll> c(N + 1);
    for (ll i = 0; i <= N; i++) {
        c[i] = mp[b[i]];
    }

    ll ans = 0;
    SegmentTree st(count + 1);
    for (ll i = 0; i <= N; i++) {
        //自分より左にある自分以下の値の個数
        ans += st.getSum(0, c[i] + 1);

        //自分を追加
        st.addOne(c[i]);
    }

    cout << ans << endl;
}