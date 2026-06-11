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
    str A, B, C;
    cin >> A >> B >> C;
    if (A[A.size() - 1] == B[0] && B[B.size() - 1] == C[0]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}