#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    Int n; cin >> n;
    set<Int> t;
    rep(i, n) {
        Int tmp;
        cin >> tmp;
        t.insert(tmp);
    }
    Int ans = 1;
    for (auto tt : t) {
        ans = tt / __gcd(tt, ans) * ans;
    }
    cout <<ans << endl;
}