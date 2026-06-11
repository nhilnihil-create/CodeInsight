#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

ll q;
vector<ll> vec;

int main() {
    fastInp;

    ll n, k;
    cin >> n >> k;
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    ll ans = 0, curS = 0;
    for (int i = 0; i < k; i++) curS += vec[i];
    vector<ll> pref, suf;
    pref.push_back(0);
    suf.push_back(0);
    for (int i = 0; i < n; i++) {
        pref.push_back(pref.back() + max(vec[i], 0ll));
    }

    for (int i = n - 1; i >= 0; i--) {
        suf.push_back(suf.back() + max(vec[i], 0ll));
    }

    reverse(suf.begin(), suf.end());

    for (int i = 0; i < n - k + 1; i++) {
        ans = max(ans, pref[i] + suf[i + k] + max(curS, 0ll));
        curS -= vec[i];
        if (i + k < n) curS += vec[i + k];
    }
    cout << ans;
    return 0;
}