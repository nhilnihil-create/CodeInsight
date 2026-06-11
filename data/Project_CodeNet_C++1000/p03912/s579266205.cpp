#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int X[100005];
int cnt[100005];
int mod[100005];
int pena[100005];

int main() {
    cin >> N >> M;
    rep(i, N) cin >> X[i];
    rep(i, N) cnt[X[i]]++;
    rep(i, N) mod[X[i] % M]++;
    int ans = 0;
    rep(i, M / 2 + 1) {
        if (i == ((M - i) % M)) {
            ans += mod[i] / 2;
            pena[i] = mod[i];
            continue;
        }
        int a = min(mod[i], mod[M - i]);
        ans += a;
        // printf("%d-%d: %d\n", i, M - i, a);
        pena[i] = pena[M - i] = a;
    }
    // cout << ans << endl;
    int m = *max_element(X, X + N);
    // rep(i, m + 1) printf("%d: %d %d\n", i, cnt[i], pena[i % M]);
    rep(i, m + 1) {
        if (cnt[i] % 2 == 1) {
            cnt[i]--;
            pena[i % M]--;
        }
    }
    // rep(i, m + 1) printf("%d: %d %d\n", i, cnt[i], pena[i % M]);
    rep(i, M) {
        if (pena[i] > 0) {
            ans -= (pena[i] + 1) / 2;
            /*
            for (int j = i; j < m + 1; j += i) {
                int a = min(pena[i], cnt[j]);
                cnt[j] -= a;
                pena[i] -= a;
                if (pena[i] == 0) break;
            }
            */
        }
    }
    // rep(i, m) if (cnt[i]) printf("%d: %d\n", i, cnt[i]);
    rep(i, m + 1) ans += cnt[i] / 2;
    cout << ans << endl;

    return 0;
}
