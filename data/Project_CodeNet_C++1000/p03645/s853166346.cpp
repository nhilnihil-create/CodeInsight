#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N, M, a, b;
    cin >> N >> M;
    map<int, int> AB1, ABN;
    string ans = "IMPOSSIBLE";
    rep(i,M) {
        cin >> a >> b;
        if (a == 1) ++AB1[b];
        if (a == N) ++ABN[b];
        if (b == 1) ++AB1[a];
        if (b == N) ++ABN[a];
    }
    if (AB1.size() != 0 && ABN.size() != 0) {
        for (auto x : AB1) {
            if (ABN[x.first] > 0) {
                ans = "POSSIBLE";
            }
        }
    }
    cout << ans << endl;
}
