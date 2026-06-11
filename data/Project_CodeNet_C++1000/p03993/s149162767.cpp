#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a[n];

    int ans = 0;
    rep(i, n) {
        int b;
        cin >> b;
        b--;
        for (auto e : a[i]) {
            if (e == b) {
                ans++;
                break;
            }
        }
        a[b].push_back(i);
    }

    cout << ans << endl;
    return 0;
}
