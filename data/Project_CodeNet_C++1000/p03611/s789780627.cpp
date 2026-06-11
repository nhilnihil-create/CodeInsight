#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        a.push_back(a[i] + 1);
        a.push_back(a[i] - 1);
    }
    vector<int> ans(110000);
    rep(i, a.size()) {
        if (a[i] >= 0) ans[a[i]]++;
    }
    int Max = 0;
    rep(i, ans.size()) Max = max(Max, ans[i]);
    cout << Max << endl;
}