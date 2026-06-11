//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    ll l;
    cin >> n >> l;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    if(n == 2) {
        if(l > a[0] + a[1]) {
            cout << "Impossible" << endl;
        } else {
            cout << "Possible" << endl << 1 << endl;
        }
        return 0;
    }
    bool x = false;
    int jj = -1;
    rep(i, n-1) {
        if(a[i] + a[i+1] >= l) {
            x = true;
            jj = i;
        }
    }

    
    vi ans;
    

    if(!x) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        rep(i, jj) {
            ans.push_back(i);
        }
        for(int i = n-2; i>=jj; --i) {
            ans.push_back(i);
        }
        rep(i, n-1) {
            cout << ans[i]+1 << '\n';
        }
    }
}