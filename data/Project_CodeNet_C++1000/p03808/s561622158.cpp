#include<iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5 + 1;

ll A[MAX_N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    ll k = N * (N + 1) / 2;
    if (sum % k) {
        cout << "NO" << endl;
        return 0;
    }
    k = sum / k;
    ll kk = 0;
    for (int i = 0; i < N; i++) {
        ll d = A[(i + 1) % N] - A[i] - k;
        if (d == 0) continue;
        else if (d < 0) {
            if (d % N) {
                cout << "NO" << endl;
                return 0;
            }
            else kk -= d / N;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (kk != k) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}