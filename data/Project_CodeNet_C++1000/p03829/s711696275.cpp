#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPR(i, n) for (int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define OUT(x) std::cout << (x) << std::endl
typedef long long ll;

int main() {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    ll x[n];
    REP(i, n) {
        cin >> x[i];
    }
    ll ans = 0;
    REP(i, n - 1) {
        if ((x[i + 1] - x[i]) * a < b) {
            ans += (x[i + 1] - x[i]) * a;
        } else {
            ans += b;
        }
    }
    OUT(ans);
}