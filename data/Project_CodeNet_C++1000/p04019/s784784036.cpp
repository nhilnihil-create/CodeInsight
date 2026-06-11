#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    string S;
    cin >> S;

    ll Nb = 0, Wb = 0, Sb = 0, Eb = 0;
    REP(i, S.length()) {
        if(S[i] == 'N') {
            Nb = 1;
        }
        if(S[i] == 'W') {
            Wb = 1;
        }
        if(S[i] == 'S') {
            Sb = 1;
        }
        if(S[i] == 'E') {
            Eb = 1;
        }
    }

    if(!(Nb ^ Sb) && !(Wb ^ Eb)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}