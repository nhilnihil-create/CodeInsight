#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int ans = 0;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->second % 2 != 0) ans++;
    }
    cout << ans << endl;
}