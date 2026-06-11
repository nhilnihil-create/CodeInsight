#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
    }

    vector<int> Index(N+1);
    rep(i, 0, N) {
        Index[A[i]] = i;
    }

    set<int> S;
    S.insert(-1); 
    S.insert(N);
    int ans = 0;

    rep(a, 1, N+1) {
        int i = Index[a];
        auto pos = S.lower_bound(i);
        int r = *pos;
        pos--;
        int l = *pos;
        int ci = (i - l) * (r - i);
        ans += ci * a;
        S.insert(i);
    }
    cout << ans << endl;
}