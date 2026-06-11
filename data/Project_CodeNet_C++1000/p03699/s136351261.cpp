#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<bool> rem(N, 1);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) if (A[i] % 10 == 0) rem[i] = 0;

    int ans = sum;
    if (sum % 10 == 0) for (int i = 0; i < N; i++) if (rem[i]) {
        ans -= A[i];
        break;
    }

    if (sum % 10 == 0 && ans == sum) ans = 0;

    cout << ans << endl;
    return 0;
}