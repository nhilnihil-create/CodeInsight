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

    ll busNum         = 1;
    ll passengerIndex = 0;
    for (ll i = 1; i < N; i++) {
        bool tooCrowded = (i - passengerIndex) >= C;
        bool isTimeOver = passengersTime[i] > (passengersTime[passengerIndex] + K);

        if (tooCrowded || isTimeOver) {
            busNum++;
            passengerIndex = i;
            // cout << endl << "NextBus:" << passengersTime[passengerIndex] << "+" << K << endl;
        }
        // cout << passengersTime[i] << " ";
    }

    cout << busNum << endl;

    return 0;
}