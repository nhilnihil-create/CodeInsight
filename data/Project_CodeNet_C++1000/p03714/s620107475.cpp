#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> a(3 * N);
    vector<ll> lmax(3 * N);

    {
        ll sum = 0;
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < 3 * N; ++i) {
            cin >> a[i];
            sum += a[i];
            que.push(a[i]);
            if (que.size() > N) {
                sum -= que.top();
                que.pop();
            }
            lmax[i] = sum;
        }
    }

    ll ans = -1e18;
    {
        ll sum = 0;
        priority_queue<int> que;
        for (int i = 3 * N - 1; i >= N; --i) {
            sum += a[i];
            que.push(a[i]);
            if (que.size() >= N) {
                if (que.size() > N) {
                    sum -= que.top();
                    que.pop();
                }
                ans = max(ans, lmax[i - 1] - sum);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
