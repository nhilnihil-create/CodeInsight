#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int N;
    ll x;
    cin >> N >> x;
    vector<ll> a(N);
    REP(i, N) cin >> a[i];
    
    ll ans = INF;
    auto b = a;
    REP(i, N) {
        ll sum = 0;
        REP(j, N) sum += b[j];
        ans = min(ans, sum + x * i);
        REP(j, N) {
            if (j - i - 1 < 0) b[j] = min(b[j], a[j - i - 1 + N]);
            else b[j] = min(b[j], a[j - i - 1]);
        }
    }
    cout << ans << "\n";
    return 0;
}
