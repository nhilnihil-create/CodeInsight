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
    ll l;
    cin >> n >> l;
    vector<ll> a(n);
    int p = -1;
    rep(i,n){
        cin >> a[i];
        if(i > 0){
            if(a[i] + a[i-1] >= l){
                p = i;
            }
        }
    }
    if(p == -1){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for(int i = 1; i < p; ++i) cout << i << endl;
    for(int i = n-1; i > p; --i) cout << i << endl;
    cout << p << endl;
    return 0;
}
