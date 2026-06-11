#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll mod = 1000000007;

int main() {
    ll N, A, ans;
    cin >> N;
    map<int, int> mp;
    rep(i,N) {
        cin >> A;
        ++mp[A];
    }
    if (N % 2 == 0) {
        bool ok = true;
        for (auto x : mp) {
            if (x.first % 2 != 1) ok = false;
            if (x.second != 2) ok = false;
        }
        if (ok) {
            ans = 1;
            rep(i,N/2) ans = (ans * 2) % mod;
            cout << ans << endl;
        } else cout << 0 << endl;
    } else {
        bool ok = true;
        for (auto x : mp) {
            if (x.first == 0) {
                if (x.second != 1) ok = false;
            } else {
                if (x.first % 2 != 0) ok = false;
                if (x.second != 2) ok = false;
            }
        }
        if (ok) {
            ans = 1;
            rep(i,N/2) ans = (ans * 2) % mod;
            cout << ans << endl;
        } else cout << 0 << endl;
    }
    
    
}

