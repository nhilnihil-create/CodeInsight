#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

class BinaryIndexedTree {
public:
    BinaryIndexedTree(ll N) : N_(N), bit_(N + 1, 0) {}
    void add(ll a, ll w) {
        for (ll x = a; x <= N_; x += (x & -x)) {
            bit_[x] += w;
        }
    }
    ll sum(ll a) {
        ll result = 0;
        for (ll x = a; x > 0; x -= (x & -x)) {
            result += bit_[x];
        }
        return result;
    }
private:
    ll N_;
    vector<ll> bit_;
}; 

int main() {
    ll N, M;
    cin >> N >> M;

    struct P {
        ll l, r;
        bool operator<(const P& rhs) const {
            return r - l < rhs.r - rhs.l;
        }
    };

    vector<P> ps(N);
    for (ll i = 0; i < N; i++) {
        cin >> ps[i].l >> ps[i].r;
    }
    sort(ps.begin(), ps.end());

    BinaryIndexedTree bit(M + 1);

    ll c = 0;
    //O(M)のループ
    for (ll d = 1; d <= M; d++) {
        //幅がd未満のものを数えておく
        //d自体のループに含まれているわけではないのでこのループはO(M)とは別にO(N)
        while (c < N && (ps[c].r - ps[c].l) < d) {
            //bit使っているのでここでO(log M),全体O(N log M)
            bit.add(ps[c].l, 1);
            bit.add(ps[c].r + 1, -1);
            c++;
        }

        //幅がd以上の駅には必ず停まることができる
        ll ans = N - c;

        //それ未満の場合はシミュレーション
        //このループはO(log d)なので間に合う
        for (ll i = 0; i <= M; i += d) {
            //ここでO(log M).全体でO(M (log M)^2)
            ans += bit.sum(i);
        }
        cout << ans << endl;
    }
}