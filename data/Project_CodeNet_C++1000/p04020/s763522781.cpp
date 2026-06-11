#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    rep(i,n) {
        cin >> a[i];
    }
    ll ans = 0;
    rep(i,n) {
        ans += a[i]/2;
        a[i] %= 2;
        if(a[i] == 1) if(a[i+1] >= 1) {
            ans += 1;
            a[i]--;
            a[i+1]--;
        }
    }
    cout << ans << endl;
}
