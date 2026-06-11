#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
    ll i, j, k;
    ll N, x;
    cin >> N >> x;
    vll A(N);
    for(auto &e : A)
        cin >> e;
    ll ans = 0;
    if(A[0] > x) {
        ans += A[0] - x;
        A[0] = x;
    }
    for(i = 1; i < N; i++) {
        ll now = A[i - 1] + A[i];
        if(now > x) {
            ans += now - x;
            A[i] -= now - x;
        }
    }
    cout << ans << endl;

    return 0;
}
