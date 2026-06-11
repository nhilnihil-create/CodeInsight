#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5 + 100;
int n;
ll k;
ll a[maxN];
ll pref[maxN];
int f[maxN];
void upd(int v) {
    while (v < maxN) {
        f[v]++;
        v = (v | (v - 1)) + 1;
    }
}
int get(int v) {
    int ans = 0;
    while (v > 0) {
        ans += f[v];
        v &= (v - 1);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    vector < pair < ll, int > > all;
    vector < ll > cords;
    for (int i = 0; i <= n; i++) {
        all.emplace_back(pref[i] - k * i, i);
    }
    sort(all.begin(), all.end());
    ll cnt = 0;
    for (auto it : all) {
        cnt += get(it.second + 1);
        upd(it.second + 1);
    }
    cout << cnt;
    return 0;
}
