#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> ma;
    rep(i, N) {
        cin >> A[i];
        ma[A[i]]++;
    }

    stack<ll> st;
    for (auto m : ma) {
        ll num = m.second - 1;
        rep(j, num) {
            if (st.empty())
                st.push(m.first);
            else
                st.pop();
        }
    }

    set<ll> cnt;
    while (!st.empty()) {
        cnt.insert(st.top());
        st.pop();
    }

    ll ans = (ll)ma.size() - (ll)cnt.size();
    cout << ans << endl;
}