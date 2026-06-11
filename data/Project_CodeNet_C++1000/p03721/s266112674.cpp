#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    Int k;
    int n; cin >> n >> k;
    vector<int> a(n), b(n);
    vector<Int> cnt(100001);
    //rep(i, n) {
    //    cin >> a[i] >> b[i];
    //}
    vector<int> c(n+1);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        cnt[a] += (Int)b;
    }
    int ii = 0;
    for (int i = 1; i < 100001; i++) {
        if (cnt[i] >= (Int)k) {
            cout << i << endl;
            break;
        }
        k -= (Int)cnt[i];
        //cout << k << endl;
    }
}
