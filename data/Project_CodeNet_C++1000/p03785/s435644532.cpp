#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, C, K;
    cin >> N >> C >> K;

    vector<ll> time(N);
    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }

    sort(time.begin(), time.end());

    ll count = 1;
    ll j = 0;
    for (ll i = 0; i < N; i++) {
        if (time[i] > time[j] + K || i - j + 1 > C) {
            // cout << i << endl;
            j = i;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
