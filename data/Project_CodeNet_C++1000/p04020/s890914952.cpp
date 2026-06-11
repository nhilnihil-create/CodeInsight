#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }

    ll sum = 0, prev = -1;
    rep(i, N) {
        if (prev > 0) {
            sum += min(prev, A[i]);
            A[i] -= min(prev, A[i]);
            sum += A[i] / 2;
            A[i] -= (A[i] / 2) * 2;
            prev = A[i];
        } else {
            sum += (A[i] / 2);
            A[i] -= (A[i] / 2) * 2;
            prev = A[i];
        }
    }

    cout << sum << endl;
}