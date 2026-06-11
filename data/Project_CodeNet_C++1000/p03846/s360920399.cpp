#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

const int MOD = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b;
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    if (n%2==0) {
        for (int i=0; i<n; i+=2) {
            if (a[i] == a[i+1]) {
                b.push_back(a[i]);
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    } else {
        for (int i=1; i<n; i+=2) {
            if (a[i] == a[i+1]) {
                b.push_back(a[i]);
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    int ans = 1;
    rep(i, b.size()) {
        ans *= 2;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}