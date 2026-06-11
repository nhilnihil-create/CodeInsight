#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }
    sort(all(a));

    int ans = 0;
    rep(i, n-1){
        if(a[i] != a[i+1]){
            ans++;
        }
    }
    if(ans % 2 == 0){
        ans++;
    }
    cout << ans << endl;

    return 0;
}