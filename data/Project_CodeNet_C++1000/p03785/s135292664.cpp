#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll N, C, K;
    cin >> N >> C >> K;
    vector<ll>T(N);
    ll ans, passenger;
    ll first = 0;
    ans = 1;
    passenger = 0;

    for (int i = 0; i < N; i++) {
        cin >> T.at(i);
    }

    sort(T.begin(), T.end());

    for (int i = 0; i < N; i++) {
        if (first == 0) {
            first = T[i];
        }
        if (passenger < C && T[i] <= first+K) {
            passenger += 1;
        } else {
            passenger = 1;
            first = T[i];
            ans += 1;
        }
    }

    cout << ans << endl;
}
