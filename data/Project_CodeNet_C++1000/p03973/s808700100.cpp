#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N; cin >> N;
    vector<Int> A(N); for (auto &a : A) cin >> a;
    Int ans = 0, curr = 0;
    for (int i = 0; i < N; i++) {
        int t = (A[i] - 1) / (curr + 1);
        ans += t;
        if (i == 0) curr = 1;
        else if (t == 0) curr = max(curr, A[i]);
    }
    cout << ans << '\n';
    return 0;
}