#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long int64;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int64> B(N - 1);
    rep(i, N - 1) B[i] = A[i] + A[i + 1];
    int id = max_element(B.begin(), B.end()) - B.begin();
    if(B[id] < L) {
        cout << "Impossible" << '\n';
    } else {
        cout << "Possible" << '\n';
        rep(i, id) cout << i + 1 << '\n';
        for(int i = N - 1; i >= id + 1; --i) cout << i << '\n';
    }
    return 0;
}
