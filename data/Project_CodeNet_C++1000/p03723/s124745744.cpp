#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    ll a;
    ll b;
    ll c;
    cin >> a >> b >> c;

    ll cnt = 0;
    bool isFind = false;
    if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
        isFind = true;
    } else if (a == b && b == c) {
        cnt = -1;
        isFind = true;
    }
    while (!isFind) {
        ll tempA = a / 2;
        ll tempB = b / 2;
        ll tempC = c / 2;

        a = tempB + tempC;
        b = tempA + tempC;
        c = tempA + tempB;

        cnt = cnt + 1;
        if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
            isFind = true;
        } else if (a == b && b == c) {
            cnt = -1;
            isFind = true;
        }
    }

    cout << cnt << endl;
}