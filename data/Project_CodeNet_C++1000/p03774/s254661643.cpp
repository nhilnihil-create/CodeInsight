#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(N), c(M), d(M);
    rep(i,N) cin >> a.at(i) >> b.at(i);
    rep(i,M) cin >> c.at(i) >> d.at(i);
    rep(i,N) {
        int ans;
        int dist;
        int minimum = INFINITY;
        rep(j,M) {
            dist = abs(a.at(i) - c.at(j)) + abs(b.at(i) - d.at(j));
            if (dist < minimum) {
                minimum = dist;
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }
}
