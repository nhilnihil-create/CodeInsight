#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    cin >> a;
    int n = a.size();
    vector<int> x;
    int tmp = 0;
    for (int i = n - 1; i >= 0; i--) {
        tmp |= 1 << (a[i] - 'a');
        if (tmp == (1 << 26) - 1) {
            tmp = 0;
            x.emplace_back(i);
        }
    }
    tmp = 0;
    int cnt = 0;
    string ans;
    while (!x.empty()) {
        tmp = 0;
        int z = *x.rbegin();
        x.pop_back();
        for (; cnt < z; cnt++) {
            tmp |= 1 << (a[cnt] - 'a');
        }
        rep(i, 0, 26) {
            if (!((tmp >> i) & 1)) {
                ans.push_back('a' + i);
                break;
            }
        }
        while (a[cnt] != *ans.rbegin()) cnt++;
        cnt++;
    }
    tmp = 0;
    for (; cnt < n; cnt++) {
        tmp |= 1 << (a[cnt] - 'a');
    }
    rep(i, 0, 26) {
        if (!((tmp >> i) & 1)) {
            ans.push_back('a' + i);
            break;
        }
    }
    cout << ans << endl;

    return 0;
}