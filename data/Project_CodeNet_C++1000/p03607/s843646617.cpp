#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        if (cnt[a]) cnt[a]--;
        else cnt[a]++;
    }
    int ans = 0;
    for (auto& p : cnt) {
        if (p.second) ans++;
    }
    cout << ans << endl;
}
