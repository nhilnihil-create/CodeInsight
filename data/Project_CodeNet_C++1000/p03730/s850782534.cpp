#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int A, B, C;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> A >> B >> C;
    rep(k, B) {
        if ((k*A-C)%B==0) {
            cout << "YES" << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;
}