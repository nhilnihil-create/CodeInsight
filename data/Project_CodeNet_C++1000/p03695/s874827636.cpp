#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> a;
int main() {
    cin >> N;
    a.resize(N);
    rep(i, N) cin >> a[i];

    map<string, ll> mp;
    ll free = 0;
    rep(i, N) {
        if (1 <= a[i] && a[i] <= 399) {
            mp["gray"]++;
        } else if (400 <= a[i] && a[i] <= 799) {
            mp["brown"]++;
        } else if (800 <= a[i] && a[i] <= 1199) {
            mp["green"]++;
        } else if (1200 <= a[i] && a[i] <= 1599) {
            mp["mizu"]++;
        } else if (1600 <= a[i] && a[i] <= 1999) {
            mp["ao"]++;
        } else if (2000 <= a[i] && a[i] <= 2399) {
            mp["ki"]++;
        } else if (2400 <= a[i] && a[i] <= 2799) {
            mp["dai"]++;
        } else if (2800 <= a[i] && a[i] <= 3199) {
            mp["red"]++;
        } else {
            free++;
        }
    }
    ll min_v = mp.size();
    if (min_v == 0 && free > 0) {
        min_v = 1;
    }
    ll max_v = (ll)mp.size() + free;
    cout << min_v << " " << max_v << endl;
}