#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

using ll = long long;

bool solve() {

    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    ll sum_A = accumulate(all(A), 0ll);
    ll n_stones_per_operation = (ll)N * (N + 1) / 2;

    if (sum_A % n_stones_per_operation) {
        return false;
    }

    ll n_operations = sum_A / n_stones_per_operation;

    vector<ll> diff_A(N);
    REP(i, N - 1) diff_A[i] = A[i] - A[i + 1];
    diff_A[N - 1] = A[N - 1] - A[0];
    
    REP(i, N) diff_A[i] += n_operations;

    return all_of(all(diff_A), [&](ll x) { return x >= 0 && x % N == 0; });
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}
