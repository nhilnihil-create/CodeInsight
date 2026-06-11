#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

template <class T>
class BIT {
    public:
        int n;
        std::vector<T> x;
        T sum(int r) const {
            T S = 0;
            for (r = r - 1; r >= 0; r = (r & (r + 1)) - 1)
                S += x[r];
            return S;
        }
        BIT(int n_ = 0) : n(n_), x(n + 1, 0) {}
        int size() const { return n; }
        void add(int k, const T &a) {
            for (; k < n; k |= k + 1) x[k] += a;
        }
        void set(int k, const T &a) { add(k, a - sum(k, k + 1)); }
        // [l r) の総和
        T sum(int l, int r) const { return sum(r) - sum(l); }
};

template <class T>
class BITRange {
    private:
        BIT<T> a, b;
        T sum(int r) const { return a.sum(r) + b.sum(r) * r; }
        void add(int r, const T &x) {
            a.add(r, x * r);
            b.add(r, -x);
        }
    public:
        BITRange(int n = 0) : a(n), b(n) {}
        int size() const { return a.size(); }
        T sum(int l, int r) const { return sum(r) - sum(l); }
        void add(int l, int r, const T &x) {
            add(l, -x);
            add(r, x);
        }
};


signed main() {
    ll N,M;
    cin>>N>>M;
    vector<vector<PLL>> u(M+1); // u[s]: 頂点数sの名産物のリスト
    rep(i,0,N){
        PLL p;
        cin>>p.first>>p.second;
        u[p.second-p.first+1].push_back(p);
    }
    auto bit = BITRange<ll>(M+10);
    ll confi = N; // 必ず1回以上取得できる名産物の種類数
    cout<<confi<<endl; // d=1のとき
    rep(d, 2, M+1){
        confi -= u[d-1].size();
        for (auto p : u[d-1]){
            bit.add(p.first, p.second+1, 1);
        }
        ll opt = 0;
        for (ll j=0; j<=M; j+=d){
            opt += bit.sum(j, j+1);
        }
        cout<<confi+opt<<endl;
    }
    return 0;
}
