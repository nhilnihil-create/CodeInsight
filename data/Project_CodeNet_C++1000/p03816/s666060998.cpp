#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        mp[a]++;
    }

    int even = 0;
    for (auto &x:mp) {
        if (x.second % 2 == 0) even++;
    }

    int ans = mp.size();
    if (even % 2 == 1) ans--;
    cout << ans << endl;
    return 0;
}

