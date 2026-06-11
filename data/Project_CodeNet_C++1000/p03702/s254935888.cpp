#include <iostream>

using namespace std;

typedef long long ll;
ll N, A, B;
ll h[114514];

int main() {
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    ll l = 0;
    ll r = 1e9;

    while (l != r) {
        auto mid = (l + r) / 2;
        ll a = 0;
        for (int i = 0; i < N; i++) {
            if (h[i] > mid * B) {
                a += ((h[i] - mid * B) + (A - B - 1)) / (A - B);
            }
        }
        if (a <= mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;
}
