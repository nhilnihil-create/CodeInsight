#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const double PI = acos(-1.);
const int MOD = 1000 * 1000 * 1000 + 7;

ll get(int r, vector<ll> &bit) {
    ll res = 0;
    for (; r > -1; r = r & -r) {
        res += bit[r];
    }
    return res;
}

void upd(int i, vector<ll> &bit, int delta) {
    for (; i < bit.size(); i = i & -i) {
        bit[i] += delta;
    }
    return;
}

int main() {
    //ios_base::sync_with_stdio(0);
    int N;
    ll ans = 1;
    cin >> N;
    ll x;
    stack<ll> st;
    for (int i = 1; i <= N; ++i) {
        cin >> x;
        st.push(x);
        if (x < st.size() * 2 - 1) {
            ans *= (ll) st.size();
            ans %= MOD;
            st.pop();
        }
    }
    for (ll i = 2; i <= st.size(); ++i) {
        ans *= i;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}