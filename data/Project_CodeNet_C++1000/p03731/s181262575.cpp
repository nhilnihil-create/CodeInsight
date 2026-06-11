#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    ll n, span;
    cin >> n >> span;
    ll ans = span;
    ll t, prev = 0;
    rep(i,n) {
        cin >> t;
        ans += min(t-prev, span);
        prev = t;
    }
    cout << ans << endl;
    return 0;
}