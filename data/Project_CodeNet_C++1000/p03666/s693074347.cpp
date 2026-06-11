#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    if(c == d) {
        rep(j, n) {
            ll k = a + (n-1-2*j)*c;
            if(b == k) {
                cout << "YES" << endl;
                return 0;
            }
        }

        cout << "NO" << endl;
        return 0;
    }

    rep(j, n) {
        ll u = a + (n-1-j)*c - j*d;
        ll v = a - j*c + (n-1-j)*d;
        if(u <= b && b <= v) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}