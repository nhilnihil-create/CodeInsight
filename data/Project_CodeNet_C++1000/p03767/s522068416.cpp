#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;
    N *= 3;
    ll a[N];
    rep(i, N) cin >> a[i];

    sort(a, a+N);
    ll sum = 0;

    for (int i = N/3; i < N; i += 2) {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}