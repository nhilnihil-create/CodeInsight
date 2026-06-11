#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    ll takahashi = 1;
    ll aoki = 1;

    for (int i = 0; i < N; i++) {
        ll T, A;
        cin >> T >> A;
        ll j;
        j = max((takahashi+T-1)/T, (aoki+A-1)/A);
        takahashi = T*j;
        aoki = A*j;
    }
    cout << takahashi+aoki << endl;
}
