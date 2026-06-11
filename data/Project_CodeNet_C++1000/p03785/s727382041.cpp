#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    ll N, C, K;
    cin >> N >> C >> K;
    vector<ll> passengersTime(N);
    for (ll i = 0; i < N; ++i) {
        cin >> passengersTime[i];
    }

    sort(passengersTime.begin(), passengersTime.end());

    ll busNum       = 1;
    ll busLeaveTime = 1 + K;
    for (ll i = 0; i < N;) {
        ll indexNext = i;
        for (ll j = 0; j < C; ++j) {
            if (i + j >= N) break;
            if (passengersTime[i + j] <= busLeaveTime) {
                indexNext = i + j;
            }
        }
#ifdef SOURCE_TEST
        cout << "busLeaveTime:" << busLeaveTime << endl;
        for (ll j = i; j <= indexNext && j < N; ++j) {
            cout << passengersTime[j] << " ";
        }
        cout << endl;
#endif
        i = indexNext + 1;
        if (i < N) {
            busNum++;
            busLeaveTime = passengersTime[i] + K;
        }
    }

    cout << busNum << endl;

    return 0;
}