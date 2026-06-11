#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll min_num = N;
    for (ll i = N; i >= 1; i--) {
        if (N <= i * (i + 1) / 2) {
            min_num = min(min_num, i);
        }
    }
    ll sum = min_num * (min_num + 1) / 2;
    for (ll i = 0; i < min_num; i++) {
        if (sum - i == N) {
            for (ll j = 1; j <= min_num; j++) {
                if (j == i) continue;
                cout << j << endl;
            }
            return 0;
        }
    }
    return 0;
}