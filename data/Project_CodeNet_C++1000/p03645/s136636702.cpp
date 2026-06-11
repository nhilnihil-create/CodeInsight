#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;

    bool to_mid[N+1] = {}, to_n[N+1] = {};
    int a, b;
    rep(i, M) {
        cin >> a >> b;
        if (a==1) to_mid[b] = true;
        else if (b==N) to_n[a] = true;
    }

    string ans = "IMPOSSIBLE";
    rep(i, N+1) {
        if (to_mid[i] && to_n[i]) ans = "POSSIBLE";
    }

    cout << ans << endl;

    return 0;
}