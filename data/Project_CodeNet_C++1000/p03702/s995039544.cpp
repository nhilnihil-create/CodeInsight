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

ll N, A, B, H[100000];

bool check(int n) {
    ll rest = n;
    REP(i, N) {
        if (H[i] - (B * n) > 0)
            rest -= (H[i] - (B * n) + A - B - 1) / (A - B);
    }
    return rest >= 0;
}

int main() {
    cin >> N >> A >> B;
    REP(i, N) cin >> H[i];

    int ng = 0, ok = 1e9;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if (check(mid)) ok = mid;
        else            ng = mid;
    }
    cout << ok << endl;
    return 0;
}