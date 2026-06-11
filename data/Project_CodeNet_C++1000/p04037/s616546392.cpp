#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, tip, ofs, cnt;
llint a[MAXN];
vector <llint> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i=1; i<n; i++) {
        ofs--;
        if (a[i] == a[i-1]) {
            tip = !tip;
            continue;
        }
        if ((a[i] - a[i-1]) % 2 == tip) v.push_back(a[i-1] + 1-tip - ofs);
        tip = 0;
    }
    for (auto x : v) {
        llint val = x + ofs;
        if (val == 1 || val == 2) {
            cout << "First";
            return 0;
        }
        if (val > 1) cnt++;
    }
    if ((a[n-1] + tip + cnt) % 2 == 0) cout << "First"; else cout << "Second";
    return 0;
}
