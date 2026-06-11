#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];

    set<int> B;
    for (auto a : A) {
        if (B.count(a) == 1) {
            B.erase(a);
        } else {
            B.insert(a);
        }
    }
    int ans = B.size();
    cout << ans << '\n';

    return 0;
}