#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]--;
    int ans = 0;
    rep(i, n) {
        if(i == a[a[i]]) {
            ans++;
        }
    }
    cout << ans/2 << endl;
}