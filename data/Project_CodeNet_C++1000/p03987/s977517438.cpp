#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

template <class T>
class SegmentTree {
    public:
        int N;
        vector<T> dat;
        T def;
        std::function<T(T, T)> operation;

        SegmentTree(int _n, T _def=1001001001, function<T(T, T)> _operation=[](T a, T b){return min(a, b);});
        T query(int a, int b, int k=0, int l=0, int r=-1);
        void update(int k, T a);
};

template <class T>
SegmentTree<T>::SegmentTree(int _n, T _def, function<T(T, T)> _operation):
    def(_def), operation(_operation) {
    N = 1;
    while (N < _n) N *= 2;
    dat = vector<T>(2*N-1, def);
}

template <class T>
T SegmentTree<T>::query(int a, int b, int k, int l, int r) {
    if (r < 0) r = N;

    if (r <= a || b <= l) return def;
    if (a <= l && r <= b) return dat[k];
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return operation(vl, vr);
}

template <class T>
void SegmentTree<T>::update(int k, T a) {
    k += N - 1;
    dat[k] = a;

    while (0 < k) {
        k = (k - 1) / 2;
        dat[k] = operation(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    SegmentTree<int> st(N);
    rep(i, N) st.update(i, A[i]);

    vector<ll> dp(N);
    rep(i, N) {
        int l = -1, r = i;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (st.query(mid, i + 1) == A[i]) r = mid;
            else l = mid; 
        }
        dp[i] = (l >= 0 ? dp[l] : 0) + (ll)A[i] * (i - l);
    }

    ll ans = 0;
    rep(i, N) ans += dp[i];
    cout << ans << endl;
}