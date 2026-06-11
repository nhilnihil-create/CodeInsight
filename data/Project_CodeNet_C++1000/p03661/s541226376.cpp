#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), sums(n+1);
    ll sum = 0;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        sum += a[i];
        sums[i+1] += a[i] + sums[i];
        //cout << sums[i+1] << " : ";
    }


    ll ans = 1e18;
    for(int i = 1; i < n; i++) {
        ll b = sum - sums[i];
        ans = min(ans, abs(b - sums[i]));
    }

    cout << ans << endl;
}