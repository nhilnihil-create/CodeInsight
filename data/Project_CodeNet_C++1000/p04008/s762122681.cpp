#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N, K; cin >> N >> K;
    vector<int> A(N); for (auto &a : A) cin >> a, a--;
    int ans = 0;
    if (A[0] != 0) ans++, A[0] = 0;
    vector<vector<int>> G(N);
    for (int i = 1; i < N; i++) {
        G[A[i]].push_back(i);
    }
    function<int(int)> recur = [&](int i) {
        int t = 0;
        for (auto child : G[i]) {
            t = max(t, recur(child));
        }
        if (A[i] != 0 && t == K - 1) ans++, t = -1;
        return t + 1;
    };
    recur(0);
    cout << ans << endl;
    return 0;
}