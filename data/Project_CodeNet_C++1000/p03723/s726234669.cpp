#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C;
    cin >> A >> B >> C;
    if (A == B && B == C && A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
        ll AA, BB, CC;
        AA = B / 2 + C / 2;
        BB = A / 2 + C / 2;
        CC = A / 2 + B / 2;
        A = AA, B = BB, C = CC;
        ans++;
    }

    cout << ans << endl;
}