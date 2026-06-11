#include <bits/stdc++.h>
using namespace std;
using Int = long long;
const int MOD = 1000000007;
struct SegTree {
    int N;
    vector<int> A;
    SegTree(int n) {
        N = 1; while (N < n) N *= 2;
        A.resize(2 * N);
    }
    void addrange(int L, int R, int val) {
        L += N, R += N;
        while (L < R) {
            if (L & 1) {
                A[L] = (A[L] + val) % MOD;
                L++;
            }
            if (R & 1) {
                R--;
                A[R] = (A[R] + val) % MOD;
            }
            L /= 2, R /= 2;
        }
    }
    int get(int idx) {
        idx += N;
        int ans = 0;
        while (idx > 0) {
            ans = (ans + A[idx]) % MOD;
            idx /= 2;
        }
        return ans;
    }
    void set(int idx, int val) {
        int orig = get(idx);
        addrange(idx, idx + 1, (val - orig + MOD) % MOD);
    }
    void add(int idx, int val) {
        addrange(idx, idx + 1, val);
    }
};
int main() {
    int N; cin >> N;
    SegTree st(2 * N + 1);
    st.set(0, 1);
    for (int i = 0; i < N; i++) {
        int val = st.get(i);
        st.add(i + 1, val);
        st.addrange(i + 1 + 2, i + 1 + N + 1, val);
    }
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans = (ans + (Int)st.get(i) * (N - 1) % MOD * (N - 1)) % MOD;
    }
    for (int i = N; i < 2 * N + 1; i++) {
        ans = (ans + st.get(i)) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
