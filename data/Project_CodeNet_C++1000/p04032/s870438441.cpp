#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    /* xxを探す */
    REP(i, n-1) {
        if(s[i] == s[i+1]) {
            cout << i+1 << " " << i+2;
            return 0;
        }
    }

    /* xyxを探す */
    REP(i, n-2) {
        if(s[i] == s[i+2]) {
            cout << i + 1 << " " << i + 3;
            return 0;
        }
    }

    cout << "-1 -1" << endl;

    return 0;
}
