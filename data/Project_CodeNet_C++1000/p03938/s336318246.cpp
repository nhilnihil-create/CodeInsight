#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, amin = 0, bmin = 0;
    cin >> N;
    vector<int> p(N), ad(N + 1, 0), bd(N + 1, 0), a(N, 0), b(N, 0);
    rep(i, N) {
        cin >> p[i];
        bd[p[i]] = -i;
        p[i]--;
        ad[p[i]] = i;
    }
    rep(i, N - 1) {
        a[i + 1] = a[i] + 1;
        a[i + 1] += ad[i + 1];
        b[i + 1] = b[i] - 1;
        b[i + 1] += bd[i + 1];
        amin = min(amin, a[i + 1]);
        bmin = min(bmin, b[i + 1]);
    }
    rep(i, N) {
        a[i] -= amin - 1;
        b[i] -= bmin - 1;
    }
    rep(i, N) {
        cout << a[i];
        if (i == N - 1) cout << "\n";
        else cout << " ";
    }
    rep(i, N) {
        cout << b[i];
        if (i == N - 1) cout << "\n";
        else cout << " ";
    }
}