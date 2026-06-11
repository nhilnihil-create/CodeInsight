#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
// using ll = long long;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    bool find = false;
    rep(i, b) {
        ll num = a * i;
        ll div = num % b;
        if (div == c) {
            find = true;
            break;
        }
    }

    if (find)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}