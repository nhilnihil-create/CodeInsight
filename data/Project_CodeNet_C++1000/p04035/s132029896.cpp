#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int max2 = 0, maxi;
    rep(i, N - 1) {
        int s = a[i] + a[i + 1];
        if (s > max2) {
            max2 = s;
            maxi = i;
        }
    }
    if (max2 < L) {
        cout << "Impossible\n";
    } else {
        cout << "Possible\n";
        rep(i, maxi) {
            cout << i + 1 << "\n";
        }
        for (int i = N - 1; i > maxi + 1; i--) {
            cout << i << "\n";
        }
        cout << maxi + 1 << "\n";
    }
}