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
    ll q, h, s, d;
    cin >> q >> h >> s >> d;
    ll n;
    cin >> n;

    cout << (n / 2) * min(8 * q, min(4 * h, min(2 * s, d))) +
                (n % 2) * min(4 * q, min(2 * h, s))
         << endl;
}