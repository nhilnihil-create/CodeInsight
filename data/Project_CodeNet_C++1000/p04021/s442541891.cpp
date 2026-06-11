#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> ma;
    rep(i, N) {
        cin >> A[i];
        ma[A[i]] = i;
    }

    sort(all(A));
    ll ans = 0;
    rep(i, N) {
        if (abs(ma[A[i]] - i) % 2 == 1)
            ans++;
    }

    cout << ans / 2 << endl;

    return 0;
}