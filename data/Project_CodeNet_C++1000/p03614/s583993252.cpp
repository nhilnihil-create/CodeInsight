#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
int N;

signed main()
{
    cin >> N;
    vector<int> p(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> p[i];
    }
    int cnt = 0;
    for (int i = 1; i < N; ++i) {
        if (p[i] == i) {
            swap(p[i], p[i + 1]);
            ++cnt;
        }
    }
    if (p[N] == N) {
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}