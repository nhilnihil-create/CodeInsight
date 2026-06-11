#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

template <typename T>
class SegmentTree {
   public:
    SegmentTree(vector<T> &base, function<T(T, T)> fn_, T e_) {
        fn = fn_;
        e = e_;
        n = 1;
        while (n < base.size()) n *= 2;

        node.resize(2 * n - 1, e);
        REP(i, 0, base.size())
        node[n - 1 + i] = base[i];
        for (int i = n - 2; i >= 0; i--) node[i] = fn(node[2 * i + 1], node[2 * i + 2]);
    }

    // 0-origin
    void update(int i, T x) {
        i += n - 1;
        node[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            node[i] = fn(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    // 0-origin, [a, b)
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return e;
        if (a <= l && r <= b) return node[k];

        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return fn(vl, vr);
    }

    int find_leftest(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l || node[k] > x) return b;
        if (k >= n - 1) return k - (n - 1);
        int idx = find_leftest(a, b, x, 2 * k + 1, l, (l + r) / 2);
        if (idx == b) idx = find_leftest(a, b, x, 2 * k + 2, (l + r) / 2, r);
        return idx;
    }

    int find_rightest(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l || node[k] > x) return a - 1;
        if (k >= n - 1) return k - (n - 1);
        int idx = find_rightest(a, b, x, 2 * k + 2, (l + r) / 2, r);
        if (idx == a - 1) idx = find_rightest(a, b, x, 2 * k + 1, l, (l + r) / 2);
        return idx;
    }

    void print(int w = 4) {
        int prev = 0;
        for (int i = 1; i <= n; i *= 2) {
            for (int j = prev; j < prev + i; j++) {
                cout << setw(n * w / i) << setfill(' ') << node[j];
            }
            cout << endl;
            prev += i;
        }
    }

   private:
    int n;
    vector<T> node;
    function<T(T, T)> fn;
    T e;
};

int main() {
    int N; cin >> N;
    vector<int> A(N);
    REP(i, 0, N) cin >> A[i];
    SegmentTree<int> seg(A, [](auto l, auto r) { return min(l, r); }, INT32_MAX);

    ll ans = 0;
    REP(i, 0, N) {
        int l = seg.find_rightest(0, i, A[i]);
        int r = seg.find_leftest(i + 1, N, A[i]);
        ans += (ll)A[i] * (i - l) * (r - i);
    }
    cout << ans << endl;
    return 0;
}