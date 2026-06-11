#include<iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5 + 10;
const ll MOD = 1e9 + 7;

int T[MAX_N], A[MAX_N];
bool t_is_constant[MAX_N], a_is_constant[MAX_N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> T[i];
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) {
        if (T[i - 1] != T[i]) t_is_constant[i] = true;
    }
    for (int i = N; i >= 1; i--) {
        if (A[i + 1] != A[i]) a_is_constant[i] = true;
    }
    ll ans = 1;
    for (int i = 1; i <= N; i++) {
        if (t_is_constant[i] && a_is_constant[i] && T[i] != A[i]) {
            cout << 0 << endl;
            return 0;
        }
        if (t_is_constant[i] && !a_is_constant[i] && T[i] > A[i]) {
            cout << 0 << endl;
            return 0;
        }
        if (!t_is_constant[i] && a_is_constant[i] && T[i] < A[i]) {
            cout << 0 << endl;
            return 0;
        }
        if (!t_is_constant[i] && !a_is_constant[i]) ans = (ans * min(T[i], A[i])) % MOD;
    }
    cout << ans << endl;
    return 0;
}