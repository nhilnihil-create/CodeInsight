#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
ll dx[4] = { 0, 1, 0, -1 };
ll dy[4] = { 1, 0, -1, 0 };
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll N, sum = 0;
    cin >> N;
    set<int> st;
    for (int i = 1;; ++i) {
        sum += i;
        st.insert(i);
        if (sum >= N) {
            int diff = sum - N;
            if (diff != 0) {
                st.erase(st.find(diff));
            }
            for (auto num : st) {
                cout << num << endl;
            }
            return 0;
        }
    }
    return 0;
}