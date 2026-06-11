#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
typedef long long ll;

const int mod = 1e+9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    bool flag = true;
    if (n % 2 == 0){
        rep(i, n / 2){
            if (a[2 * i] != 2 * i + 1 || a[2 * i + 1] != 2 * i + 1) flag = false;
        }
    }
    else {
        if (a[0] != 0) flag = false;
        rep(i, (n - 1) / 2){
            if (a[2 * i + 1] != 2 * (i + 1) || a[2 * i + 2] != 2 * (i + 1)) flag = false;
        }
    }
    if (flag) { 
        ll ans = 1;
        rep(i, n/2) ans = ans * 2 % mod;
        cout << ans << endl;
    }
    else cout << 0 << endl;
}