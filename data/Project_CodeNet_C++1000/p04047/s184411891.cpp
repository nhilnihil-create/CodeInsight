#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    rep(i,2*n) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    rep(i,n) {
        ans += min(a[2*i], a[2*i+1]);
    }
    cout << ans << endl;
}