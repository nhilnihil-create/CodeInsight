#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;
int main() {
    ll N;
    cin >> N;
    vector<ll> T(N), A(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll maxl = max_element(T.begin(), T.end()) - T.begin();
    reverse(A.begin(), A.end());
    ll maxr = max_element(A.begin(), A.end()) - A.begin();
    maxr = N - 1 - maxr;
    reverse(A.begin(), A.end());

    bool flag = true;
    if (maxl > maxr) {
        flag = false;
    }

    if (T[maxl] != A[maxr]) {
        flag = false;
    }

    ll sum = 1;
    for (int i = 1; i < maxl; i++) {
        if (T[i] == T[i - 1]) {
            sum *= T[i];
            sum %= M;
        }
    }
    for (int i = N - 2; i > maxr; i--) {
        if (A[i] == A[i + 1]) {
            sum *= A[i];
            sum %= M;
        }
    }

    ll gap = maxr - maxl - 1;
    while (gap > 0) {
        sum *= T[N - 1];
        sum %= M;
        gap--;
    }

    cout << (flag ? sum : 0) << endl;
}
