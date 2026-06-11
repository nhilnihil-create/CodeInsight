#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int n, a, b;

bool judge(int k, vector<int>& v) {
    int attack = 0;
    for (int i = 0; i < n; i++) {
        int t = v[i] - b * k;
        if (t <= 0) continue;
        attack += t / (a - b);
        if (t % (a - b) != 0)
            attack++;
    }
    return k >= attack;
}

signed main() {
    cin >> n >> a >> b;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int r = 0;
    int l = (int)1e9;
    while (l - r > 1) {
        int mid = (l + r) / 2;
        if (judge(mid, v))
            l = mid;
        else
            r = mid;
    }
    cout << l << "\n";
}