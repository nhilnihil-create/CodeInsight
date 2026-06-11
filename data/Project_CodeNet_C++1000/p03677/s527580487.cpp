#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL N, M; cin >> N >> M;
        vector<UL> A(N); rep(i, N) { cin >> A[i]; A[i]--; }
        vector<LL> FC(M + 2);
        vector<LL> FL(M + 2);
        rep(i, N - 1) {
            if (A[i] > A[i + 1]) {
                FC[0] += A[i + 1] + 2;
                FL[0] += -1;
                FC[A[i + 1] + 1] += M - (A[i] - A[i + 1]) - 1;
                FL[A[i + 1] + 1] += 1;
                FL[A[i] + 2] -= 1;
            }
            else {
                FC[0] += (A[i + 1] - A[i]);
                FL[A[i] + 2] += -1;
                FL[A[i + 1] + 1] += 1;
                FC[A[i + 1] + 1] += A[i + 1] - A[i] - 1;
            }
        }
        rep(i, M) FL[i + 1] += FL[i];
        rep(i, M) FC[i] += FL[i];
        rep(i, M) FC[i + 1] += FC[i];
        LL ans = (LL)1e15;
        rep(i, M) ans = min(ans, FC[i]);
        cout << ans << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}
