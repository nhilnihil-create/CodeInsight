#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= 2 * n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    //cout << v.size() << endl;
    for (int i = 0; i + 1 < (int)v.size(); i += 2) {
        ans += v[i + 1];
    }
    cout << ans << endl;
    return 0;
}
