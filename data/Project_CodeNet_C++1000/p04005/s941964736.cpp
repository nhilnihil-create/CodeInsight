#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    vector<ll> vec = {A, B, C};
    sort(ALL(vec));
    cout << vec[0]*vec[1]*(vec[2]%2) << endl;
    return 0;
}