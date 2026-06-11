/**
 * Title: AtCoDeer and Election Report
 * Url: https://atcoder.jp/contests/abc046/tasks/arc062_a
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<numeric>
#include<functional>
#include<sstream>
#include<iomanip>

using namespace std;

#define ll long long

int main() {
    int n; cin >> n;
    vector<ll> t(n), a(n);
    for(int i=0; i<n; i++) cin >> t[i] >> a[i];
    ll ti=1, ai=1;
    for(int i=0; i<n; i++) {
        ll k = max((ll)ceil(ti/(long double)t[i]), (ll)ceil(ai/(long double)a[i]));
        ti = k*t[i];
        ai = k*a[i];
    }
    cout << ti+ai << endl;
    return 0;
}