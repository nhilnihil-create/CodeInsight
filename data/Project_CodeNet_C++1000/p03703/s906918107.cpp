#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

template <typename T>
class BIT {
    using u32 = uint_fast32_t;
    // bit : 1-indexed,各要素の値を持つ
    vector<T> bit;
    u32 n;

   public:
    BIT(u32 N) {
        n = N;
        bit.assign(N + 1, 0);
    }

    // i番目の値にxを加える
    void add(u32 i, T x) {
        while (i <= n) {
            bit[i] += x;
            // i&-i : iの最右1bit
            i += i & -i;
        }
    }

    // a1～aiの総和を返す
    T sum(u32 i) {
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    // ai～ajの総和を返す
    T range_sum(u32 i, u32 j) { return sum(j) - sum(i - 1); }
};

template <typename T>
ll inversion_number(vector<T> &v) {
    int n = v.size(), cnt = 1;
    set<T> st;
    unordered_map<T, int> f;
    for (int i = 0; i < n; i++) st.insert(v[i]);
    for (auto ite = st.begin(); ite != st.end(); ++ite) f[*ite] = cnt++;

    BIT<ll> tree(cnt - 1);
    ll res = 0;
    for (int j = 0; j < n; j++) {
        res += j - tree.sum(f[v[j]]);
        tree.add(f[v[j]], 1);
    }
    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N + 1, 0), s(N + 1, 0), x(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        x[i] = s[i] - i * K;
    }
    cout << N * (N + 1) / 2 - inversion_number(x) << endl;
    return 0;
}