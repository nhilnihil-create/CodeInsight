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
    string A, B;
    cin >> A >> B;

    vector<char> As(101, '0'), Bs(101, '0');
    REP(i, A.length()) {
        As[As.size() - A.length() + i] = A[i];
    }
    REP(i, B.length()) {
        Bs[Bs.size() - B.length() + i] = B[i];
    }

    REP(i, As.size()) {
        if(As[i] > Bs[i]) {
            cout << "GREATER" << endl;
            return 0;
        }
        if(As[i] < Bs[i]) {
            cout << "LESS" << endl;
            return 0;
        }
    }
    cout << "EQUAL" << endl;
    return 0;
}