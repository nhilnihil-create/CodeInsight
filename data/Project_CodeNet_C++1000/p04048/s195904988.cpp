#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
typedef unsigned long long ll;
const int M = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 300 + 5;

ll gcd(const ll a, const ll b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    ll n, x;
    cin >> n >> x;
    ll TotalLength = n - x;
    ll TriangleLength = x;
    ll quo;
    ll res = 0;
    while (true) {
        if (TriangleLength == 0) {
            cout << res << endl;
            return 0;
        }
        quo = TotalLength / TriangleLength;
        res += 3 * quo * TriangleLength;
        ll temp = TotalLength;
        TotalLength = TriangleLength;
        TriangleLength = temp % TriangleLength;
    }
}
