#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using vi = vector<int>;
const int MOD = 1e9 + 7;


int main() {
    int N;
    int a = 0;
    cin >> N;
    vi A(N);
    vi even(N);
    vi odd(N);

    rep(i, N) {
        cin >> A[i];
    }
    sort(all(A));

    rep(i, N / 2) {
        even[2 * i] = 2 * i + 1;
        even[2 * i + 1] = 2 * i + 1;
    }

    odd[0] = 0;
    rep(i, (N - 1) / 2) {
        odd[2 * i + 2] = 2 * i + 2;
        odd[2 * i + 1] = 2 * i + 2;
    }

    if (A == even) a = 1;
    if (A == odd) a = 1;
    ll ans = 0;
    if (a == 1) {
        ans = 1;
        rep(i, N / 2) {
            ans *= 2;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}