#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    map<ll, set<ll>> mp;
    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        mp[a].insert(i + 1);
    }
    mp[0].insert(0);

    set<ll> st;
    vector<ll> ans(N + 1, 0);
    for (auto itr = mp.rbegin(); itr != mp.rend(); itr++) {
        auto next = itr;
        next++;
        if (next == mp.rend()) {
            break;
        }

        //setのマージ
        bool sw = (st.size() < itr->second.size());
        if (sw) {
            swap(st, itr->second);
        }
        for (auto e : itr->second) {
            st.insert(e);
        }

        ans[*st.begin()] += (itr->first - next->first) * st.size();
    }

    for (ll i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
}