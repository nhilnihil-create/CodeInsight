#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef vector<ll> vel;
typedef vector<str> ves;
#define REP(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define rep(i, b) REP(i, 0, b)
const ll mod = 1000000007;
const double pi = 3.14159265358979;

int main() {
    ll A, B;
    cin >> A >> B;
    if (A == B) {
        cout << "Draw" << endl;
    }
    else {
        if (A == 1) {
            cout << "Alice" << endl;
        }
        else if (B == 1) {
            cout << "Bob" << endl;
        }
        else if (A < B) {
            cout << "Bob" << endl;
        }
        else {
            cout << "Alice" << endl;
        }
    }
}