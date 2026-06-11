#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    set<int> se;
    rep(i, N) se.insert(A[i]);
    map<int, int> ma;
    rep(i, N) ma[A[i]] = i;

    int cnt = 0;
    int idx = 0;
    for (auto s: se) {
        if (ma[s] % 2 != idx % 2) cnt++;
        idx++;
    }

    cout << cnt / 2 << endl;
}