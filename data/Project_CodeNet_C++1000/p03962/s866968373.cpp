#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef vector<ll> vel;
typedef vector<str> ves;
#define REP(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define rep(i, b) REP(i, 0, b)

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll count = 0;
    if (a == b && b == c && c == a) {
        count = 1;
    }
    else {
    if (a != b) {
        count ++;
    }
    if (b != c) {
        count ++;
    }
    if (c != a) {
        count ++;
    }
    }
    cout << count << endl;
}