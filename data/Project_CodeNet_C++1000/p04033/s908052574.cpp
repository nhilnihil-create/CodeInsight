#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll a, b;
    cin >> a >> b;

    string res;
    if(a > 0 && b > 0) {
        res = "Positive";
    } else if(a <= 0 && b >= 0) {
        res = "Zero";
    } else {
        if((abs(a) - abs(b) + 1) % 2 == 0) {
            res = "Positive";
        } else {
            res = "Negative";
        }
    }

    cout << res << endl;

    return 0;
}