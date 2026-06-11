#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

ll cs[200001];

int main() {
    int N, a;
    cin >> N;
    REP(i, N) {
        cin >> a;
        cs[i + 1] = a + cs[i];
    }

    ll ans = 1000000000000000000LL;
    FOR(i, 1, N) {
        ans = min(abs(cs[N] - 2 * cs[i]), ans);
    }
    cout << ans << endl;
    return 0;
}
