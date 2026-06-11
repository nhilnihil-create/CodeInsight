#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef vector<ll> vel;
typedef vector<str> ves;
#define REP(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define rep(i, b) REP(i, 0, b)

int main() {
    ll a, b, h;
    cin >> a >> b >> h;
    cout << (a + b) * h / 2 << endl;
}