#include <bits/stdc++.h>
using namespace std;
using Int = long long;
struct SegTree {
    int N;
    vector<Int> data;
    SegTree(int n) {
        N = 1;
        while (N < n) N *= 2;
        data.assign(2*N, 0);
    }
    void addrange(int l, int r, Int v) {
        l += N;
        r += N;
        while (l < r) {
            if (r & 1) data[--r] += v;
            if (l & 1) data[l++] += v;
            l /= 2, r /= 2;
        }
    }
    Int operator[](int i) {
        i += N;
        Int ans = 0;
        while (i > 0) {
            ans += data[i];
            i /= 2;
        }
        return ans;
    }
};
int main()
{
    int N, M; cin >> N >> M;
    vector<int> A(N); for (auto& a : A) cin >> a, a--;
    SegTree B(2*M), C(2*M);
    for (int i = 1; i < N; i++) {
        int s = A[i-1];
        int e = A[i] < A[i-1] ? A[i]+M : A[i];
        C.addrange(0, M, e - s);
        B.addrange(s+1, e+1, -1);
        C.addrange(s+1, e+1, s+1);
    }
    Int ans = LLONG_MAX;
    for (int x = 0; x < M; x++) {
        ans = min(ans, B[x] * x + C[x] + B[x+M] * (x+M) + C[x+M]);
    }
    cout << ans << '\n';
    return 0;
}