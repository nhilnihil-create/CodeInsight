//----------------------------------------------------------------------
#include <bits/stdc++.h>
#include <numeric>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll sum = accumulate(a.begin(), a.end(), 0);
    if(sum % 10 != 0) {
        cout << sum << endl;
        return 0;
    }
    int min_v = 1e9+1;
    rep(i, n) {
        if(a[i] % 10 != 0) {
            min_v = min(min_v, a[i]);
        }
    }
    cout << (min_v == 1e9 + 1 ? 0 : sum - min_v ) << endl;
    return 0;
}
