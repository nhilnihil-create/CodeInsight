#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N, M;
    cin >> N >> M;
    ll ans = min(M / 2, (N * 2 + M) / 4);
    cout << ans << endl;
}
