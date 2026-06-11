#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, n) for (int i = a; i <= (n); ++i)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
    int N; cin >> N;

    vector<ll> a;
    rep(i, 3 * N) {
       int n; cin >> n;
       a.push_back(n);
    }

    sort(a.begin(), a.end(), greater<ll>());

    ll ans = 0;
    for (int i = 1; i <= 2 * N - 1; i+=2) {
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}

