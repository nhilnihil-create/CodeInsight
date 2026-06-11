#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> order(N + 1);
    REP(i, 1, N + 1) {
        int a; cin >> a;
        order[a] = i;
    }

    ll ans = 0;
    set<int> used = {0, N + 1};
    REP(i, 1, N + 1) {
        int l, r;
        auto itr = used.lower_bound(order[i]);
        r = (*itr);
        l = *(--itr);
        // cout << "# i : " << i << " idx : " << order[i] << " l : " << l << " r : " << r << endl;
        ans += (ll)i * (order[i] - l) * (r - order[i]);
        used.insert(order[i]);
    }
    cout << ans << endl;
    return 0;
}