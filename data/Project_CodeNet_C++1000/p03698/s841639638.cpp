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
    string S;
    cin >> S;

    vector<bool> flag((int)'z' - (int)'a' + 1, false);
    REP(i, S.length()) {
        int id = (int)S[i] - (int)'a';
        if(flag[id]) {
            cout << "no" << endl;
            return 0;
        }
        flag[id] = true;
    }

    cout << "yes" << endl;
    return 0;
}