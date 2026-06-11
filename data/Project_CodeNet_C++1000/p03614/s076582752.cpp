#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

void solve() {
    int N, ans = 0, i = 0;
    cin >> N;
    vector<int> p(N);
    rep(j, N) cin >> p[j];
    while (i < N) {
        if (p[i] == i + 1) {
            ans++;
            if (i < N - 1 && p[i + 1] == i + 2) i++;
        }
        i++;
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
}