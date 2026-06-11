#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

// N^P mod M（ただしM == -1の時はmodを取らない）
template<typename T>
T RS(T N, T P, T M){
    if(P == 0) {
        return 1;
    }
    if(P < 0) {
        return 0;
    }
    if(P % 2 == 0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) {
        return N * RS(N,P - 1,M);
    }
    return N * RS(N, P-1, M) % M;
}

/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
struct SegmentTree {
    const T INF = numeric_limits<T>::max();
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    SegmentTree(int n_) : n(), dat(n_ * 4, INF) { // 葉の数は 2^x の形
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};

int main() {
    int N;
    cin >> N;
    ll x;
    cin >> x;
    vector<ll> vec(N);
    SegmentTree<ll> seg(2 * N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
        seg.update(i,vec.at(i));
        seg.update(i + N,vec.at(i));
    }
    ll cnt = INF;
    int min_id = -1;
    for(int i = 0;i < N;i++) {
        if(cnt > vec.at(i)) {
            cnt = vec.at(i);
            min_id = i;
        }
    }
    ll ret = INF;
    for(ll i = 0;i < N;i++) {
        ll count = cnt + x * i;
        for(int j = 0;j < N;j++) {
            if(j != min_id) {
                count += seg.query(j,j + i + 1);
            }
        }
        chmin(ret,count);
        min_id--;
        min_id %= N;
        if(min_id < 0) {
            min_id += N;
        }
    }
    cout << ret << endl;
}       