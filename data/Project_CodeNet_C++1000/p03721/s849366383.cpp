//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    ll n, k;
    cin >> n >> k;
    vector<P> a(n);
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    ll num = 0;
    rep(i, n) {
        num += a[i].second;
        if(num >= k) {
            cout << a[i].first << endl;
            return 0;
        }
    }
    return 0;
}
