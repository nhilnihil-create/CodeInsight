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
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (ll)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    string S;
    cin >> S;
    vector<int> cnt(26, 0);
    ll ans = SZ(S) * (SZ(S) - 1) / 2 + 1;
    REP(i, SZ(S)) ans -= cnt[S[i] - 'a']++;
    cout << ans << "\n";
    return 0;
}
