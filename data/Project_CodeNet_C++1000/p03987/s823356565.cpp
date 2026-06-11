#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> pos(N + 1);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        pos[a] = i;
    }

    set<int> st;
    st.emplace(-1);
    st.emplace(N);
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ll tmp = i;
        auto itr = st.lower_bound(pos[i]);
        tmp *= (*itr - pos[i]);
        --itr;
        tmp *= (pos[i] - *itr);
        ans += tmp;
        st.emplace(pos[i]);
    }

    cout << ans << endl;

    return 0;
}
