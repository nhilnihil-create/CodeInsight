#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

int main() {
    int N;
    cin >> N;

    string S, T;
    cin >> S >> T;

    int ans = 2 * N;
    rep(i, N)  {
        if (S.substr(i) == T.substr(0, N-i)) {
            ans = N + i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}