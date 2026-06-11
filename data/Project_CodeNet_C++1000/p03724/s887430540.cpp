#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N, M, a, b;
    cin >> N >> M;
    vector<int> c(N, 0);
    rep(i, M) {
        cin >> a >> b;
        c[a - 1]++;
        c[b - 1]++;
    }
    rep(i, N) {
        if (c[i] % 2) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}