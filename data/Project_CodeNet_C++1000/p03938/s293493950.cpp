#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> p(n), q(n);
    rep(i,n){
        cin >> p[i];
        --p[i];
        q[p[i]] = i+1;
    }
    vector<ll> a(n), b(n);
    rep(i,n){
        a[i] = 20005 * (i + 1);
        b[i] = 20005 * (n - 1 - i) + q[i];
    }
    rep(i,n-1) cout << a[i] << " ";
    cout << a[n-1] << endl;
    rep(i,n-1) cout << b[i] << " ";
    cout << b[n-1] << endl;
    return 0;
}
