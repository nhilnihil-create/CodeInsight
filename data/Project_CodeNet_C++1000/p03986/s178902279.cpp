#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    string S;
    cin >> S;

    int ans = 0, start = 0;
    rep(i, S.size()) {
        if (S[i] == 'S')
            ++start;
        else {
            if (start == 0)
                ++ans;
            else
                --start;
        }
    }
    ans += start;

    cout << ans << endl;

    return 0;
}